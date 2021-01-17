#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.length())
            return 0;
        short i = 0, j = 0;
        int curmax = 0;
        set<char> myset;
        while (i < s.length())
        {
            char c = s[i];
            while (myset.find(c)!= myset.end())
            {
                myset.erase(s[j]);
                j++;
            }
            myset.insert(c);
            curmax = max(i - j + 1, curmax);
            i++;
        }
        return curmax;
    }
};