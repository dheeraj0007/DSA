#include <iostream>
using namespace std;

class StackClass
{
    int top;
    int capacity;
    int *arr;

public:
    StackClass(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }
    int isEmpty()
    {
        return (top == -1);
    }
    void push(int n)
    {
        if (top == capacity - 1)
        {
            cout << "overflow " << endl;
            return;
        }
        top++;
        arr[top] = n;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow " << endl;
            return -1;
        }
        int ans = arr[top];
        top--;
        return ans;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty! " << endl;
            return -1;
        }
        return arr[top];
    }
    int isFull()
    {
        if (top == capacity - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int size()
    {
        return top + 1;
    }
};

struct Node
{
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};
class StackClass2
{
    int sz;
    Node *head;

public:
    StackClass2()
    {
        head = NULL;
        sz = 0;
    }
    void push(int n)
    {
        Node *temp = new Node(n);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
        int ans = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        sz--;
        return ans;
    }
    int top()
    {
        if (sz != 0)
        {
            return head->data;
        }
        else
        {
            return -1;
        }
    }
    int isEmpty()
    {
        return (sz == 0);
    }
    int size()
    {
        return sz;
    }
};
int main()
{

    return 0;
}