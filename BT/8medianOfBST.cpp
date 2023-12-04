#include <iostream>
#include "Node.cpp"
#include <stack>
#include <vector>
using namespace std;

//  gfg - Median of BST
float findMedian(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    Node *curr = root;
    stack<Node *> st;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    if (ans.size() % 2 != 0)
    {
        return ans[(ans.size()) / 2];
    }
    else
    {
        int mid = ans.size() / 2;
        return float((ans[mid] + ans[mid - 1]) / 2);
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
    cout << findMedian(root) << endl;
    return 0;
}