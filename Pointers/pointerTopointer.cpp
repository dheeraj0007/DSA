#include <iostream>
using namespace std;
int main()
{
    int x = 5;
    int *p = &x;
    *p = 6;
    int **q = &p;
    int ***r = &q;
    cout << *p << endl; // value at p
    cout << *q << endl; // value at q i.e. address of p
    cout << *(*q) << endl;
    cout << *(*r) << endl;
    cout << **(*r) << endl;
    ***r = 10;
    cout << x << endl;
    **q = *p + 2;
    cout << x << endl;
    return 0;
}