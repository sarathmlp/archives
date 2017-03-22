#include <iostream>
#include <fstream>
#include <map>
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

class HostInfo
{
    public:
        long hostId;
        map<string, string> MacToInterface;
};

int AddMactoInterface(HostInfo& obj)
{
    vector<string> interface;
    struct ifaddrs *ifaddr, *ifa;
    struct ifreq s;
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    char buf[20];

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
                    sprintf(buf," %02x", (unsigned char)s.ifr_addr.sa_data[i]);
                    data.append(buf);
                }
            }
            obj.MacToInterface.insert
                (pair<string, string>(ifa->ifa_name, data));
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}

void Display(HostInfo& obj)
{
    cout<<"Hosid: "<<hex<<obj.hostId<<endl;
    map<string, string>::iterator it = obj.MacToInterface.begin();
    for (int i=0;i<obj.MacToInterface.size();i++)
    {
        cout<<"Interface: "<<it->first<<"\t"<<"Mac: "<<it->second<<endl;
        it++;
    }
}

int main(int argc, char* argv[])
{
    if (argv[1])
    {
        if ( strcmp(argv[1], "write") == 0)
        {
            HostInfo hinfo;
            long hostId = gethostid();
            hinfo.hostId = hostId;
            AddMactoInterface(hinfo);

            fstream fobj;
            fobj.open("hostinfo.dat", ios::out | ios::trunc | ios::binary);
            fobj.write((char *)&hinfo,sizeof(HostInfo));
            fobj.close();
        }

        if (strcmp(argv[1], "read") == 0)
        {
            fstream fobj;
            HostInfo hiRead;
            fobj.open("hostinfo.dat", ios::in | ios::binary);
            while ((fobj.read((char*)&hiRead, sizeof(HostInfo))) != 0)
            {
                Display(hiRead);
            }
            fobj.close();
        }
    }
    else
    {
        cout<<"Usage: ./a.out <read/write>"<<endl;
    }
    return 0;
}

