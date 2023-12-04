#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int id;

    //  printname is not defined inside class definition
    void printName();

    // // printid is defined inside class definition
    void printId()
    {
        cout << "The person's id is " << id << endl;
    }
};

void Person::printName()
{
    cout << "The person's name is " << name << endl;
}

int main()
{
    Person p1;
    p1.name = "John";
    p1.id = 100;
    p1.printId();
    p1.printName();
    return 0;
}