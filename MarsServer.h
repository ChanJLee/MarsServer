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

/*
 * magic number len 5B
 * */
const size_t MAGIC_LEN = 5;

/*
 * type len, 2B
 * */
const size_t TYPE_LEN = 2;

/*
 * package len 10B
 * */
const size_t PACKAGE_LEN = 10;

/*
 * mata data len 12B
 * */
const size_t META_DATA_LEN = TYPE_LEN + PACKAGE_LEN;

/*
 * head len
 * */
const size_t HEADER_LEN = MAGIC_LEN + META_DATA_LEN;

/**
 * magic header
 * */
const char MAGIC_HEADER[] = {0x05, 0x21, 0x05, 0x25, 0x00};

const int TYPE_IMAGE = 1;

const int TYPE_ACTION = 2;

const int TYPE_HEART_BEAT = 3;

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
	void receiveData(const std::string &data, int type);
	void sendData(const std::string &data);
	static void sigPipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
