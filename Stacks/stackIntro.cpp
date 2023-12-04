#include <iostream>
#include <stack>
using namespace std;

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;
    // behavior

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = ele;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            top--;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class StackLL
{
public:
    Node *head;
    int size = 0;
    StackLL()
    {
        head = NULL;
    }

    void push(int ele)
    {
        Node *temp = new Node(ele);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            size--;
        }
    }

    int peek()
    {
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }
    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
};

int main()
{

    /*
    // creation of stack using stl
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);

    // pop operation
    s.pop();

    cout << "Printing top element " << s.top() << endl;
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "size of stack is " << s.size() << endl;
    */

    /*
    // creation of stack using arrays
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << "Printing top element " << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << "Printing top element " << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    */

    // creation of stack using linked list
    StackLL st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Printing stack size" << st.length() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << "Printing stack size" << st.length() << endl;
    cout << "Printing the top element " << st.peek() << endl;
    cout << st.isEmpty() << endl;
    cout << st.peek() << endl;
    return 0;
}
