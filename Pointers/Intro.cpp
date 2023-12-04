#include <iostream>
using namespace std;
int main()
{
    /*

    int a = 5;
    int *p = &a;
    // Pointer arithmetic
    cout << p << endl;
    cout << p + 1 << endl;

    */

    int a = 1025;
    int *p;
    p = &a;
    cout << sizeof(int) << endl;
    cout << "Address = " << (int)p << ", value = " << *p << endl;
    cout << "Address = " << (int)(p + 1) << ", value = " << *p + 1 << endl;
    char *p0;
    p0 = (char *)p; // typecasting

    cout << sizeof(char) << endl;
    cout << "Address = " << (int)p0 << ", value = " << *p0 << endl;
    cout << "Address = " << (int)(p0 + 1) << ", value = " << *p0 + 1 << endl;

    // void pointer - generic pointer
    void *p1;
    p1 = p;
    cout << (int)p1 << endl;
    return 0;
}