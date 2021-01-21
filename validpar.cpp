#include <set>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        set<char> open = {'(', '[', '{'};
        stack<char> q;
        for (auto &it : s)
        {
            if (open.find(it) != open.end())
            {
                q.push(it);
            }
            else if (it == ')' && !q.empty() && q.top() == '(')
            {
                q.pop();
            }
            else if (it == ']' && !q.empty() && q.top() == '[')
            {
                q.pop();
            }
            else if (it == '}' && !q.empty() && q.top() == '{')
            {
                q.pop();
            }
            else
            {
                return false;
            }
        }
        return q.empty();
    }
};

int main()
{
    Solution z;
    cout << z.isValid("(]") << '\n';
}