//
// Created by chan on 2017/12/31.
//

#ifndef MARSSERVER_MARSSERVER_H
#define MARSSERVER_MARSSERVER_H

#include <cstdio>
#include <ios>

typedef int SocketServer;

const int BUFFER_SIZE = 1024;
class MarPackage {
private:
	char* mBuffer;
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
	MarPackage* mPackage;
public:
	void start();
private:
	void processClient();
	void processData(const char* buffer, std::streamsize size);
	static void sigPipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
