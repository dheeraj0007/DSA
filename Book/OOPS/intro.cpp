#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void remove_duplicates(Node *head)
{
    map<int, int> m;
    int i = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        int data = curr->data;
        if (m.find(data) == m.end())
        {
            Node *temp = curr;
            curr = curr->next;
            delete (temp);
        }
        else
        {
            m[curr->data]++;
        }
        curr = curr->next;
        i++;
    }
}

int main()
{
    // linked_list = 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
    // O / p : 12->11->21->41->43

    return 0;
}