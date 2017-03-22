#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char* argv[]) 
{
    struct in_addr ip;
    ip.s_addr = inet_addr(argv[1]); // www.google.fr IP
    struct hostent* hostnames = gethostbyaddr(&ip, sizeof(ip), AF_INET);
    if (hostnames != NULL && hostnames[0].h_name != NULL) 
    {
        printf("%s\n", hostnames[0].h_name);
        return 0;
    } 
    else 
    {
        herror("gethostbyaddr");
        return 1;
    }

}
