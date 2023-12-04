#include <iostream>
#include "Node.cpp"
#include <stack>
using namespace std;

void preOrderIt(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->val << " ";
        if (curr->right != NULL)
        {
            s.push(curr->right);
        }
        if (curr->left != NULL)
        {
            s.push(curr->left);
        }
    }
}

void inOrderIt(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty() == true)
            {
                break;
            }
            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}

void postOrderIt(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s1;
    stack<int> s2;
    s1.push(root);
    while (s1.empty() == false)
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr->val);
        if (curr->left != NULL)
        {
            s1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            s1.push(curr->right);
        }
    }
    while (s2.empty() == false)
    {
        cout << s2.top() << " ";
        s2.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    postOrderIt(root);
    return 0;
}