#include<iostream>
using namespace std;

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	system("clear");
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	if(cfd==-1)
	{
		cout<<"socket failed!"<<endl;
		return 1;
	}

	struct sockaddr_in server_sock;
	server_sock.sin_family=AF_INET;
	server_sock.sin_port=htons(6000);
	server_sock.sin_addr.s_addr=inet_addr("127.0.0.1");

	while(1)
	{
		int c=connect(cfd,(struct sockaddr*)(&server_sock),sizeof(server_sock));
		if(c==-1)
		{
			cout<<"Server not found...!!"<<endl<<"Enter 'r' to retry, 't' to terminate"<<endl;
			char ch;
			cin>>ch;
			if(ch=='r')
				continue;
			if(ch=='t')
				break;
		}

		while(1)
		{
			char msg[100];
			cout<<"Enter msg to server:"<<flush;
			cin>>msg;
			int w=write(cfd,msg,sizeof(msg));
			if(w==-1)
			{
				cout<<"writing failed!"<<endl;
				exit(1);
			}
			cout<<"Msg sent to server..."<<endl;

			char buf[100];
			int r=read(cfd,buf,sizeof(buf));
			if(r==-1)
			{
				cout<<"reading failed!"<<endl;
				exit(1);
			}

			buf[r]='\0';
			cout<<"Msg from server:"<<buf<<endl;

			cout<<"Enter 't' to terminate, any other key to continue:"<<flush;
			char ch;
			cin>>ch;
			if(ch=='t')
				return 0;
			else
				continue;
		}
	}

	close(cfd);
	return 0;
}
