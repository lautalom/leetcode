#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

////////////////TLE
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        //current keeps track of amt of elems in solution
        int i = 0, need = k, current = 0;
        //you cant optimize with a maximum if the fst in nums is the minimum
        bool found = 0;
        vector<int> sol(k, INT32_MAX);
        for (int p = 0; p < n; p++)
        {
            found = 0;
            i = 0;
            while (i < k && !found)
            {
                //if optimality condition and there are sufficient
                // elems in array to build a solution from ith elem
                if (nums[p] < sol[i] && need <= (n - p))
                {
                    sol[i] = nums[p];
                    need--;
                    //reset everything past a new addition
                    i + 1 < k ? sol[i + 1] = INT32_MAX : sol[i] = sol[i];
                    found = 1;
                }
                i++;
            }
        }
        return sol;
    }
}; TLE
///////////////////////////////////accepted
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector <int> ans;
        int r = nums.size()-k;
        for (auto &i: nums){
            //not empty and there are elms remaining
            //and i < top of stack
            while (ans.size() && r && i < ans.back()){
                ans.pop_back();
                r--;
            } 
            ans.push_back(i);
        }
        while(r){
            ans.pop_back();
            r--;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> q = {3, 5, 2, 6, 4, 6, 7, 8, 9};
    vector<int> ans = s.mostCompetitive(q, 4);
    for (auto &it : ans)
        cout << it << ' ';
}