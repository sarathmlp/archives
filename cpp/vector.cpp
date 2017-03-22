#include <iostream>
#include <vector>

using namespace std;

class Test
{
private:
    int no;
    vector<Test> vect;
public:
    Test(int val):no(val){}
    void getval()
    {
        return no;
    }
    void addToVect(Test& obj)
    {
        vect.push_back(obj);
    }
    void get(int& a)
    {
        vector<Test>::iterator it;
        for ()
        {
            a = it->getval();
        }
    }
};

int main()
{
    Test test(1);
    Test test1(1),test2(1);
    test.addToVect(test1);
}


