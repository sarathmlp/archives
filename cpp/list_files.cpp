#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>
#include <cctype>
#include <cstdio>
#include<cstdlib>
using namespace std;
void list_dir(char* dirname,int lvl)
{

    DIR *dp;
    char buffer[4096];
    struct dirent *dirp;
    struct stat filestatus;
    if((dp  = opendir(dirname))==NULL)
    {	
        exit(0);	
    }


    while((dirp=readdir(dp)) != NULL) 
    {

        if(strncmp(dirp->d_name, "..", 2) != 0 &&  strncmp(dirp->d_name, ".", 1) != 0) 
        {
            if (dirp->d_type == DT_DIR) 
            {

                for(int i=0; i < 2*lvl; i++)
                {
                    printf(" ");
                }

                cout<<dirp->d_name<<endl;
                strncpy(buffer, dirname, 4095);
                strncat(buffer, "/", 4095);
                strncat(buffer, dirp->d_name, 4095);
                list_dir(buffer, lvl+1);
            }

            else 
            {

                for(int i=0; i < 2*lvl; i++) 
                {
                    cout<<" "; 
                }
                cout<<dirp->d_name<<endl;
            }
        }
    }

    closedir(dp);

}


int main(int argc, char** argv)
{

    if(argc!=2)
        cout<<"Error";
    list_dir(argv[1],0);
    return 0;
}


