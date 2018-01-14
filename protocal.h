//
// Created by chan on 2018/1/14.
//

#ifndef MARSSERVER_PROTOCAL_H
#define MARSSERVER_PROTOCAL_H

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
	u2 type;
	u4 len;
};

struct WindowSize
{
	u4 width;
	u4 height;
};

#endif //MARSSERVER_PROTOCAL_H
