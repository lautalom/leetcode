#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        bool t = true;
        int i = 0;
        int c = k, m = 20000, n = nums.size();
        while (i < n && t)
        {
            if (nums[i])
            {
                //reset counter after every 1
                c = k;
                int j = i + 1;
                //as long as you see zeros, count them
                while (j < n && !nums[j])
                {
                    c--;
                    j++;
                }
                //if the last 1 is in last position there is no problem!
                if (c > 0 && j < n)
                {
                    t = false;
                }
                else
                    //advance i to jth position (which is a 1)
                    i = j;
            }
            else
                i++;
        }
        return t;
    }
};


//best runtime
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -k-1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(i-prev-1 < k){
                    return false;
                }
                prev = i;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> s = {1, 0, 0, 0, 1, 0, 0, 1};
    Solution q;
    cout << q.kLengthApart(s, 2) << endl;
    return 0;
}