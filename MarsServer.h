//
// Created by chan on 2017/12/31.
//

#ifndef MARSSERVER_MARSSERVER_H
#define MARSSERVER_MARSSERVER_H

#include <string>
#include "protocal.h"

class MarsServer
{
private:
	int mCurrentSocketClient = -1;
	SocketServer mSocketServer;

	WindowSize* mWindowSize;
public:
	void start();
private:
	void sendMessageRunnable();
	void readMessageRunnable();
	void receiveData(u1 *data, const MarsHeader &header);
	void sendData(u1 *data, size_t len);
	void renderImage(u1 *data, int len);
	static void sigPipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
