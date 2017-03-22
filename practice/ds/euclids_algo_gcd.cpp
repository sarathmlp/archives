#include <iostream>
using namespace std;

int calc_gcd (int a, int b);

int main()
{
    int a;
    int b;
    int gcd;

    cout << "Enter the two numbers: " << endl;
    cin >> a >> b;

    gcd = calc_gcd(a,b);

    cout << "GCD is : " << gcd << endl;
    return 0;
}

int calc_gcd (int a, int b)
{
    int rem;

    if (b == 0) {
        return a;
    }
    rem = a % b;

    return calc_gcd(b,rem);
}
