#include <iostream>
#include "Node.cpp"
using namespace std;

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
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

    // DFS (Depth First Search)
    // 1. preorder recusive traversal (root left right)
    // preOrder(root);

    // 2. inorder recusive traversal (left root right)
    // inOrder(root);

    // 3. postorder recusive traversal (left right root
    // postOrder(root);
    return 0;
}