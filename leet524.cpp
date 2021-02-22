#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string h1, string h2)
    {
        int m = h1.length(), n = h2.length(), j = 0;
        for (int i = 0; i < n && j < m; i++)
        {
            if (h1[j] == h2[i])
            {
                j++;
            }
        }
        return (j == m);
    }
    string findLongestWord(string s, vector<string> &d)
    {
        string ans = "", back = s;
        int length = 0;
        for (string &x : d)
        {
            bool a = isSubsequence(x, s);
            if (length < x.length() && a)
            {
                ans = x;
                length = x.length();
            }
            else if (length == x.length() && a)
            {
                if (x < ans)
                    ans = x;
            }
        }
        return ans;
    }
};

/*
"abpcplea"
["ale","apple","monkey","plea"]
"abpcplea"
["a","b","c"]
"apple"
["zxc","vbn"]


int main()
{
    Solution q;
    string s = "aewfafwafjlwajflwajflwafj";
    vector<string> d = {"apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf"};
    cout << q.findLongestWord(s, d) << endl;
}
*/