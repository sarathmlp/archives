#include<iostream>
using namespace std;

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include <sys/time.h>
#include<string.h>

class Socket
{
	protected:
		int sock_fd;
		struct sockaddr_in sock_addr;
	public:
		Socket();
		~Socket();
};

class Server_socket:public Socket
{
	protected:
		int connectlist[5];
		fd_set socks;
		int highsock;

	public:
		Server_socket(int port);
		int non_block(int &fd);
		void select_list();
		int new_connection();
		int read_sock();
		int data(int listnum);
		~Server_socket();
		int& ret_highsock();
		fd_set& ret_socks();
};

class Client_socket:public Socket
{
	public:
		Client_socket(int port, char* ip);
		//int connect(int port, char* ip);
		~Client_socket();
};
