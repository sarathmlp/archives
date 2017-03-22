#include<iostream>
 
using namespace std;
 
int main()
{
  int c1 = 0, c2 = 0;
    
  /* FIRST */
  for(int i=0;i<10;i++,c1++)
    for(int j=0;j<100;j++, c1++);
      //do something
 
    
  /* SECOND */
  for(int i=0; i<100; i++, c2++)
      for(int j=0; j<10; j++, c2++);
        //do something
 
  cout << " Count in FIRST = " <<c1 << endl;
  cout << " Count in SECOND  = " <<c2 << endl;
 
  return 0;
}
