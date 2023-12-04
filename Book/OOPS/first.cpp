#include <iostream>
using namespace std;

class Circle
{
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Circle()
    {
        private_variable = 10;
        protected_variable = 20;
    }
    friend class Gola;
};

class Gola
{
public:
    void display(Circle &c)
    {
        cout << "The value of private variable " << c.private_variable << endl;
        cout << "The value of private variable " << c.protected_variable << endl;
    }
};

int main()
{
    
    return 0;
}