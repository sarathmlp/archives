#include"header.h"

/*extern int connectlist[5];
extern fd_set socks;
extern int highsock;*/

int main()
{
	int readsocks,i;
	struct timeval timeout;
	system("clear");

	Server_socket obj(6000);
	cout<<"Server running..."<<endl;

	int& highsock=obj.ret_highsock();
	fd_set& socks=obj.ret_socks();

	while(true)
	{
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;

		obj.select_list();
		readsocks=select(highsock+1,&socks,(fd_set*)0,(fd_set*)0,&timeout);
		if(readsocks==-1)
		{
			perror("select");
			exit(1);
		}
		if(readsocks==0)
		{
			cout<<"*"<<flush;
		}
		else
		{
			i=obj.read_sock();
			if(i==1)
				cout<<"Connection failed!"<<endl;
			
		}
	}

	return 0;
}
