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

void MarsServer::start()
{
	std::cout << "start server" << std::endl;

	int socket_server = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_server < 0) {
		std::cerr << "open socket failed" << std::endl;
		return;
	}

	sig_t sig_result = signal(SIGTSTP, sig_pipe);
	if (sig_result == SIG_ERR) {
		std::cerr << "signal error" << std::endl;
		return;
	}

	std::cout << "signal success" << std::endl;

	struct sockaddr_in server;
	memset(&server, 0, sizeof(socket_server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(8765);

	int bind_result = bind(socket_server, (const sockaddr *) &server, sizeof(sockaddr_in));
	if (bind_result < 0) {
		std::cerr << "bind error" << std::endl;
		return;
	}

	int listen_result = listen(socket_server, 5);
	if (listen_result < 0) {
		std::cerr << "listen error" << std::endl;
		return;
	}

	struct sockaddr_in client;
	while (true) {
		socklen_t client_len = sizeof(client);
		int socket_client = accept(socket_server, (struct sockaddr *) &client, &client_len);
		if (socket_client < 0) {
			std::cerr << "accept client failed" << std::endl;
			continue;
		}

		pid_t pid = fork();
		if (pid == 0) {
			close(socket_server);
			process_conn_server(socket_client);
		}
		else {
			close(socket_client);
		}
	}
}

void MarsServer::sig_pipe(int sig)
{
	std::cout << "accept sig" << std::endl;
	if (sig == SIGTSTP) {
		exit(1);
	}
}

void MarsServer::process_conn_server(int socket)
{
	const int buffer_size = 1024;
	long size = 0;
	char buffer[buffer_size];  //定义数据缓冲区
	for (;;) {
		//等待读
		for (size = 0; size == 0; size = read(socket, buffer, buffer_size));
		//输出从客户端接收到的数据
		printf("%s", buffer);

		//结束处理
		if (strcmp(buffer, "quit") == 0) {
			close(socket);   //成功返回0，失败返回-1
			return;
		}
		sprintf(buffer, "%l bytes altogether\n", size);
		write(socket, buffer, strlen(buffer) + 1);
	}
}
