//
// Created by chan on 2017/12/31.
//

#ifndef MARSSERVER_MARSSERVER_H
#define MARSSERVER_MARSSERVER_H

#include <string>

typedef int SocketServer;

/**
 * cache size 512B
 * */
const int BUFFER_SIZE = 512;

typedef unsigned char u1;

/**
 * magic header
 * */
const u1 MAGIC_HEADER[] = {0x05, 0x21, 0x05, 0x25, 0x12, 0x12, 0x01, 0x18,};

const short TYPE_IMAGE = 1;

const short TYPE_WINDOW_SIZE = 2;

const short TYPE_HEART_BEAT = 3;

const short TYPE_ACTION = 4;

typedef unsigned int u4;
typedef unsigned short u2;

struct MarsHeader
{
	u1 header[sizeof(MAGIC_HEADER)];
	short type = -1;
	int len = -1;
};

class MarsServer
{
private:
	int mCurrentSocketClient = -1;
	SocketServer mSocketServer;
public:
	void start();
private:
	void sendMessageRunnable();
	void readMessageRunnable();
	void receiveData(u1* data, const MarsHeader& header);
	void sendData(u1* data, size_t len);
	static void sigPipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
