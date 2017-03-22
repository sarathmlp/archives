#include"header.h"

Socket::Socket()
{
	try
	{
		sock_fd=socket(AF_INET,SOCK_STREAM,0);
		if(sock_fd==-1)
			throw 1;
	}
	catch(int)
	{
		cout<<"Socket creation failed!"<<endl;
	}
}

Socket::~Socket(){}

