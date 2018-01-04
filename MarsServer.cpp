//
// Created by chan on 2017/12/31.
//

#include "MarsServer.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <sstream>
#include <stddef.h>
#include <cstdlib>

void MarsServer::start()
{
	std::cout << "start server" << std::endl;

	mSocketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (mSocketServer < 0) {
		std::cerr << "open socket failed" << std::endl;
		return;
	}

	sig_t sig_result = signal(SIGTSTP, sigPipe);
	if (sig_result == SIG_ERR) {
		std::cerr << "signal error" << std::endl;
		return;
	}

	std::cout << "signal success" << std::endl;

	struct sockaddr_in server;
	memset(&server, 0, sizeof(mSocketServer));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(8765);

	int bind_result = bind(mSocketServer, (const sockaddr *) &server, sizeof(sockaddr_in));
	if (bind_result < 0) {
		std::cerr << "bind error" << std::endl;
		return;
	}

	int listen_result = listen(mSocketServer, 5);
	if (listen_result < 0) {
		std::cerr << "listen error" << std::endl;
		return;
	}

	struct sockaddr_in client;
	socklen_t client_len = sizeof(client);
	int socket_client = accept(mSocketServer, (struct sockaddr *) &client, &client_len);
	if (socket_client < 0) {
		std::cerr << "accept client failed" << std::endl;
		return;
	}

	mCurrentSocketClient = socket_client;
	std::thread send_thread(&MarsServer::sendMessageRunnable, this);
	std::thread read_thread(&MarsServer::readMessageRunnable, this);

	send_thread.join();
	read_thread.join();
}

void MarsServer::sigPipe(int sig)
{
	std::cout << "accept sig" << std::endl;
	if (sig == SIGTSTP) {
		exit(1);
	}
}

void MarsServer::sendMessageRunnable()
{
	std::cout << "send message runnable" << std::endl;
	char arg;
	std::ostringstream os;
	while (true) {
		arg = std::cin.get();
		if (arg != 'a' && arg != 'A' &&
			arg != 'w' && arg != 'W' &&
			arg != 's' && arg != 'S' &&
			arg != 'd' && arg != 'D') {
			continue;
		}

		os.clear();
		os.write(MAGIC_HEADER, MAGIC_LEN);
		os << "0" << TYPE_ACTION << "0000000001" << arg;
		const std::string &data = os.str();
		sendData(data);
	}
}

void MarsServer::readMessageRunnable()
{
	std::cout << "read message runnable" << std::endl;
	ptrdiff_t segment_size = 0;

	std::ostringstream os;
	char buffer[BUFFER_SIZE];

	size_t cached_len = 0;

	int current_type = -1;
	int current_len = -1;

	char type_str[TYPE_LEN + 1] = {0};
	char len_str[PACKAGE_LEN + 1] = {0};
	char *scan_buffer;

	while ((segment_size = read(mCurrentSocketClient, buffer, BUFFER_SIZE)) >= 0) {
		if (segment_size == 0) {
			continue;
		}

		scan_buffer = buffer;
		if (segment_size >= HEADER_LEN) {
			if (memcmp(buffer, MAGIC_HEADER, MAGIC_LEN) == 0) {

				// copy type str
				memcpy(type_str, buffer + MAGIC_LEN, TYPE_LEN);
				current_type = atoi(type_str);

				memcpy(len_str, buffer + MAGIC_LEN + TYPE_LEN, PACKAGE_LEN);
				current_len = atoi(len_str);

				std::cout << "current type: " << current_type << " current len: " << current_len << std::endl;

				// init buffer
				os.clear();
				cached_len = 0;
				scan_buffer = buffer + HEADER_LEN;
				segment_size -= HEADER_LEN;
			}
		}

		if (current_type < 0 || current_len < 0 || segment_size == 0) {
			continue;
		}

		os.write(scan_buffer, segment_size);
		cached_len += segment_size;
		if (cached_len >= current_len) {
			const std::string &data = os.str();
			receiveData(data, current_type);
		}
	}
}

void MarsServer::receiveData(const std::string &data, int type)
{
	std::cout << data << std::endl;
}

void MarsServer::sendData(const std::string &data)
{
	const char *buffer = data.c_str();
	size_t len = data.size();
	while (len != 0) {
		ssize_t sent_len = send(mCurrentSocketClient, buffer, data.size(), 0);
		buffer += sent_len;
		len -= sent_len;
	}
}