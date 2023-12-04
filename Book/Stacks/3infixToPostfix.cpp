#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    return (
        (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'));
}
bool isHigher(char a, char b)
{
    if (a == '(')
    {
        return true;
    }
    if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '^'))
    {
        return true;
    }
    else if ((a == '*' || a == '/') && (b == '^'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(s[i]) == true)
        {
            if (st.empty() == true)
            {
                st.push(s[i]);
            }
            else
            {
                if (isHigher(st.top(), s[i]) == true)
                {
                    st.push(s[i]);
                }
                else if (st.top() == '(')
                {
                    st.push(s[i]);
                }
                else
                {
                    while (st.empty() == false && isHigher(st.top(), s[i]) == false)
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while (st.empty() == false)
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int calculator(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            int val = ch - '0';
            st.push(val);
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            int ans = 0;
            if (ch == '+')
            {
                ans = val1 + val2;
            }
            else if (ch == '-')
            {
                ans = val2 - val1;
            }
            else if (ch == '*')
            {
                ans = val1 * val2;
            }
            else if (ch == '/')
            {
                ans = val2 / val1;
            }
            st.push(ans);
        }
    }
    return st.top();
}
int main()
{
    // string str = "a+b*(c^d-e)^(f+g*h)-i";
    string str1 = "1-(     -2)";
    cout << infixToPostfix(str1) << " here " << endl;
    cout << calculator(infixToPostfix(str1));
    return 0;
}