//
// Created by chan on 2017/12/31.
//

#ifndef MARSSERVER_MARSSERVER_H
#define MARSSERVER_MARSSERVER_H

#include <cstdio>
#include <ios>

typedef int SocketServer;

const int BUFFER_SIZE = 512;

const size_t MAGIC_LEN = 5;

const size_t HEADER_LEN = 12;

const size_t TYPE_LEN = 2;

const size_t PACKAGE_LEN = 10;

const char MAGIC_HEADER[] = {0x05, 0x21, 0x05, 0x25, 0x00};

class MarPackage
{
private:
	char *mBuffer;
	int mLen;
public:
	MarPackage(size_t mLen);
	~MarPackage();
	char *getBuffer() const;
	int getLen() const;
};

class MarsServer
{
private:
	int mCurrentSocketClient = -1;
	SocketServer mSocketServer;
	MarPackage *mPackage;
public:
	void start();
private:
	void sendMessageRunnable();
	void readMessageRunnable();
	void processData(const char *buffer, size_t size);
	static void sigPipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
