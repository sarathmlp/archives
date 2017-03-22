#include"header.h"

Server_socket::Server_socket(int port)
{
	int reuse_addr = 1;
	setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,sizeof(reuse_addr));
	non_block(sock_fd);

	sock_addr.sin_family=AF_INET;
	sock_addr.sin_port=htons(port);
	sock_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	try
	{
		int b=bind(sock_fd,(struct sockaddr*)(&sock_addr),sizeof(sock_addr));
		if(b==-1)
			throw 1;

		int l=listen(sock_fd,5);
		if(l==-1)
			throw 2;
	}
	catch(int x)
	{
		if(x==1)
			cout<<"Binding failed!"<<endl;
		if(x==2)
			cout<<"Listening failed!"<<endl;
	}

	highsock=sock_fd;//initial assignment
	memset((char *) &connectlist, 0, sizeof(connectlist));

}

Server_socket::~Server_socket(){}

int& Server_socket::ret_highsock()
{
	return highsock;
}
fd_set& Server_socket::ret_socks()
{
	return socks;
}

int Server_socket::non_block(int &fd)
{
	int flag;
	flag=fcntl(fd,F_GETFL);
	if(flag==-1)
	{
		perror("fcntl");
		return 1;
	
	}
	flag=flag|O_NONBLOCK;

	if(fcntl(fd,F_SETFL,flag)==-1)
	{
		perror("set");
		return 1;
	}
}

void Server_socket::select_list()
{
	FD_ZERO(&socks);//clear the fd_set socks
	FD_SET(sock_fd,&socks);//adds FD sock_fd to socks
//	cout<<"select list created"<<endl;
	int listnum;
	for (listnum = 0; listnum < 5; listnum++) 
	{
		if (connectlist[listnum] != 0)
		{
			FD_SET(connectlist[listnum],&socks);
				if (connectlist[listnum] > highsock)
					highsock = connectlist[listnum];
		}
	}
}


int Server_socket::read_sock()
{
	int i;

	if (FD_ISSET(sock_fd,&socks))
		i=new_connection();
		if(i==1)
			return 1;
	
	int listnum;
	for (listnum = 0; listnum < 5; listnum++) 
	{
		if (FD_ISSET(connectlist[listnum],&socks))
			data(listnum);
	}
}

int Server_socket::new_connection()
{
	int connection;
	struct sockaddr_in client_sock;
	int s=sizeof(client_sock);
	int num;

	connection=accept(sock_fd,(struct sockaddr*)(&client_sock),(socklen_t*)(&s));
	if(connection==-1)
	{
		perror("accept");
		return 1;
	}

	non_block(connection);
	for (num = 0; (num < 5) && (connection != -1); num ++)
	{
		if (connectlist[num] == 0)
		{
			printf("\nConnection accepted:   FD=%d; Slot=%d\n",connection,num);
			connectlist[num] = connection;
			connection = -1;
		}
	}

	if (connection != -1) 
	{
		printf("\nNo room left for new client.\n");
		write(connection,"Sorry, this server is too busy...try again later!\n",100);
		close(connection);
	}
}

int Server_socket::data(int listnum)
{
	char buffer[100]; 
	int r;
	r=read(connectlist[listnum],buffer,sizeof(buffer));
	if(r<=0)
	{
		cout<<"Connection lost: FD="<<connectlist[listnum]<<"slot"<<listnum<<endl;
		close(connectlist[listnum]);
		connectlist[listnum] = 0;
		return 0;
	}

	buffer[r]='\0';
	write(connectlist[listnum],buffer,sizeof(buffer));
//	write(connectlist[listnum],"\n",2);
	cout<<"responded:"<<buffer<<endl;
}

