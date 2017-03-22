#include <iostream>
#include <memory>
#include <tr1/memory>

// std::auto_ptr<int> fun()
int* fun()
{
    int* pt = new int;
    *pt = 100;
    const std::tr1::shared_ptr<int> ptr(pt);
    *ptr.get() = 100;
    // throw "exception";
    return pt;
}

int main ()
{
    // std::auto_ptr<int> p2;
    // try
    // {
    //     p2 = fun();
    // }
    // catch(...)
    // {
    //     std::cout << "Exception caught\n";
    // }

    // if (p2.get() != NULL)
    //     std::cout << "p2 points to " << *p2 << '\n';

    int* ptr;
    try
    {
        ptr = fun();
    }
    catch(...)
    {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << *ptr << std::endl;
    return 0;
}
