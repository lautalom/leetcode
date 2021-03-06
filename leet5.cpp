#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int best_len = 0;
        string best_s = "";
        int n = s.length();
        for (int mid = 0; mid < n; mid++)
        {
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])
                {
                    break;
                }
                int len = 2 * x + 1;
                if (len > best_len)
                {
                    best_len = len;
                    best_s = s.substr(mid - x, len);
                }
            }
        }

        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])
                {
                    break;
                }
                int len = 2 * x;
                if (len > best_len)
                {
                    best_len = len;
                    best_s = s.substr(mid - x + 1, len);
                }
            }
        }
        if (!best_len && n)
        {
            best_len = 1;
            best_s = s.at(0);
        }
        return best_s;
    }
};

//fastest

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int start = 0;
        int len = 0;
        for(int i=0; i<length; i++){
            int left=i,right=i;
            while(s[right]==s[right+1]) {
                right++;
            }
            i=right;
            while(left > 0 && right < length-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            if(right - left > len){
                len = right - left;
                start = left;
            }
        }
        
        return s.substr(start, len+1);
        
    }
};

int main()
{
    Solution c;
    cout << c.longestPalindrome("abb") << endl;
}