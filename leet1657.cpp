#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        //all characters must coincide and individual frequencies must match
        vector<int> freq1(26, 0), freq2(26, 0), chars1(26, 0), chars2(26, 0);

        for (auto a : word1)
        {
            freq1[a - 'a']++;
            chars1[a - 'a'] = 1;
        }
        for (auto a : word2)
        {
            freq2[a - 'a']++;
            chars2[a - 'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && chars1 == chars2;
    }
};

int main()
{
    Solution q;
    string w1 = "cabbba", w2 = "abbccc";
    cout << q.closeStrings(w1, w2) << endl;
    return 0;
}