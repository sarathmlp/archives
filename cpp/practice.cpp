#include <iostream>
using namespace std;

#define MIN(a,b)  ( ( a ) < ( b ) ? ( a ) : ( b ) )

int main()
{
   int x;
   x = MIN(2+1,4);
   cout<<"MIN: "<<x<<endl;
   x = MIN(1,1+1) + 1;
   cout<<"MIN: "<<x<<endl;
   char *ptr = NULL;
   if (!ptr)
       cout << "fish" << endl;
   return 0;
}
