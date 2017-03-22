#include <iostream>
#include <algorithm>
#include <vector>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if.h>
#include <netdb.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> interface;
    struct ifaddrs *ifaddr, *ifa;
    struct ifreq s;
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    unsigned char buf[20];

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
        {
            continue;
        }
        string name(ifa->ifa_name);
        if(find(interface.begin(), interface.end(),name) == interface.end())
        {
            interface.push_back(string(ifa->ifa_name));
            strcpy(s.ifr_name, ifa->ifa_name);
            string data;
            char buf[20];
            if (0 == ioctl(fd, SIOCGIFHWADDR, &s)) 
            {
                int i;
                for (i = 0; i < 6; ++i)
                {
                    sprintf(buf," %02x", (unsigned char) s.ifr_addr.sa_data[i]);
                    data.append(buf);
                }
            }
            printf("%s\n", ifa->ifa_name);
            cout<<data<<endl;
        }
    }

    freeifaddrs(ifaddr);
    exit(EXIT_SUCCESS);
}
