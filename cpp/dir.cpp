#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    char buffer[50];
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(argv[1])) == NULL)
    {
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) 
    {
        cout << dirp->d_name << " ";
        // strcpy(buffer, argv[1]);
        // strcat(buffer, dirp->d_name);
        // struct stat buf;
        // stat(buffer, &buf);
        // cout << dirp->d_name<< " ->"<< buf.st_size << endl;
    }
    closedir(dp);
    return 0;
}
