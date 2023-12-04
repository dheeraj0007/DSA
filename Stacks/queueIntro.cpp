#include <iostream>
#include <queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int capacity)
    {
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int ele)
    {
        if (rear == size)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            arr[rear] = ele;
            rear++;
        }
    }
    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int Qfront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    bool isEmpty()
    {
        return front == rear;
    }
};

class CircularQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }
    bool enque(int value)
    {
        if (front == 0 && rear == size - 1 || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
        }
        // first element push
        else if (front == -1)
        {
            front = rear = 0;
        }

        // to maintain cyclic nature
        else if(rear==size-1 && front!=0){
            rear++;
        }

        // normal flow
        else{
            rear++;
        }
        // push intside the queue
        arr[rear] = value;
        return true;
    }
    int deque(){
        // empty queue

    }
};

int main()
{
    /*
    // Queue using STL
    // create a queue
    queue<int> q;
    q.push(11);
    cout << "Front of queue is " << q.front() << endl;
    q.push(15);
    q.push(13);
    cout << "size of queue is : " << q.size() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "size of queue is : " << q.size() << endl;
    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty" << endl;
    }
    */

    // creation of queue using arrays
    Queue q(5);
    q.push(1);
    q.push(2);
    cout << q.pop() << endl;
    cout << q.Qfront() << endl;
    q.push(3);
    q.push(4);
    q.push(5);
    while (q.isEmpty() == false)
    {
        cout << q.pop() << endl;
    }
    return 0;
}