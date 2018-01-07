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
#include <stddef.h>

void MarsServer::start()
{
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
	MarsHeader marsHeader;
	memcpy(marsHeader.header, MAGIC_HEADER, sizeof(MAGIC_HEADER));
	u1 data[sizeof(MarsHeader) + 1];

	while (true) {
		u1 arg = std::cin.get();
		if (arg != 'a' && arg != 'A' &&
			arg != 'w' && arg != 'W' &&
			arg != 's' && arg != 'S' &&
			arg != 'd' && arg != 'D') {
			continue;
		}

		marsHeader.type = TYPE_ACTION;
		marsHeader.len = 1;
		memcpy(data, &marsHeader, sizeof(MarsHeader));
		data[sizeof(MarsHeader)] = arg;
		sendData(data, sizeof(data));
	}
}

void MarsServer::readMessageRunnable()
{
	std::cout << "read message runnable, size of Header " << sizeof(MarsHeader) << std::endl;
	size_t segment_size = 0;

	u1 buffer[BUFFER_SIZE];

	size_t current_len = 0;
	MarsHeader marsHeader;
	u1 *data = NULL;

	while ((segment_size = read(mCurrentSocketClient, buffer, BUFFER_SIZE)) >= 0) {
		if (segment_size == 0) {
			continue;
		}

		if (segment_size >= sizeof(MarsHeader)) {
			if (memcmp(buffer, MAGIC_HEADER, sizeof(MAGIC_HEADER)) == 0) {

				memcpy(&marsHeader, buffer, sizeof(MarsHeader));

				std::cout << "current type: " << marsHeader.type << " current len: " << marsHeader.len << std::endl;

				if (data != NULL) {
					delete data;
					data = NULL;
				}

				// init buffer
				current_len = 0;
				data = new u1[marsHeader.len];
				memcpy(data, buffer + sizeof(MarsHeader), segment_size - sizeof(MarsHeader));
				continue;
			}
		}

		if (marsHeader.type < 0 || marsHeader.len <= 0 || data == NULL) {
			continue;
		}

		memcpy(data + current_len, buffer, segment_size);
		current_len += segment_size;
		if (current_len >= marsHeader.len) {
			receiveData(data, marsHeader);
			delete data;
			data = NULL;
		}
	}
}
void MarsServer::receiveData(u1 *data, const MarsHeader &header)
{
	if (data == NULL) {
		return;
	}
	std::cout << data << std::endl;
}

void MarsServer::sendData(u1 *data, size_t len)
{
	if (data == NULL) {
		return;
	}

	while (len != 0) {
		ssize_t sent_len = send(mCurrentSocketClient, data, len, 0);
		data += sent_len;
		len -= sent_len;
	}
}
