//
// Created by chan on 2017/12/31.
//

#ifndef MARSSERVER_MARSSERVER_H
#define MARSSERVER_MARSSERVER_H

class MarsServer
{
public:
	void start();
private:
	void process_conn_server(int s);
	static void sig_pipe(int signo);
};


#endif //MARSSERVER_MARSSERVER_H
