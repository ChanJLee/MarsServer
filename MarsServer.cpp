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
	while (true) {
		socklen_t client_len = sizeof(client);
		int socket_client = accept(mSocketServer, (struct sockaddr *) &client, &client_len);
		if (socket_client < 0) {
			std::cerr << "accept client failed" << std::endl;
			continue;
		}

		if (mCurrentSocketClient >= 0) {
			close(mCurrentSocketClient);
		}

		std::thread thread(&MarsServer::processClient, this);
		thread.join();
	}
}

void MarsServer::sigPipe(int sig)
{
	std::cout << "accept sig" << std::endl;
	if (sig == SIGTSTP) {
		exit(1);
	}
}

void MarsServer::processClient()
{
	ptrdiff_t size = 0;
	char buffer[BUFFER_SIZE];  //定义数据缓冲区
	std::ostringstream os;
	while (true) {
		os.clear();
		while ((size = read(mCurrentSocketClient, buffer, BUFFER_SIZE)) != -1) {
			os.write(buffer, (std::streamsize) size);
		}

		const std::string &str = os.str();
		processData(str.c_str(), str.size());

		if (mPackage != NULL) {
			write(mCurrentSocketClient, mPackage->getBuffer(), mPackage->getLen());
			mPackage = NULL;
		}
	}
}
void MarsServer::processData(const char *buffer, std::streamsize size)
{
	std::cout << buffer << std::endl;
}

MarPackage::MarPackage(size_t mLen)
	: mLen(mLen)
{
	mBuffer = new char[mLen];
	memset(mBuffer, 0, mLen);
}

MarPackage::~MarPackage()
{
	delete mBuffer;
}

char *MarPackage::getBuffer() const
{
	return mBuffer;
}
int MarPackage::getLen() const
{
	return mLen;
}
