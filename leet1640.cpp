#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// RESTRICTIONS
// 1 <= pieces.length <= arr.length <= 100
// the elems in pieces may be at most each elem in arr. ie =[arr[i]],[arr[j],...]
// sum(pieces[i].length) == arr.length
// the # of integers in both arrays are equal, ie if one elem is not in the other array you are done
// 1 <= pieces[i].length <= arr.length
// 1 <= arr[i], pieces[i][j] <= 100
// magnitude of numbers, helps to initialize map

//fastest
class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        int idx = 0;
        while (idx < arr.size())
        {
            bool flag = false;
            for (auto it : pieces)
            {
                if (arr[idx] == it[0])
                {
                    flag = true;
                    idx++; 
                    //found piece starting with arr[idx], check rest of elems in it
                    for (int j = 1; j < it.size(); j++)
                    {//quit if any is different
                        if (arr[idx] != it[j])
                            return false;
                        idx++;
                    }
                }
                //case pieces containts one elem: arr
                if (idx == arr.size())
                    return true;
            }
            //didnt find arr[i] among pieces.
            if (flag == false)
                return false;
        }
        return true;
    }
};

//original
class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        int n = arr.size(), ans = 1;
        map<int, int> m;
        for (int i = 0; i < n; i++)
            m[arr[i]] = i;
        for (auto &a : pieces)
        {
            int s = a[0];
            if (m.find(s) == m.end())
                ans = false;
            int j = m[s];
            int i = 0;
            while (i < a.size() && j < n && ans)
            {
                if (a[i] != arr[j])
                    ans = false;
                i++;
                j++;
            }
            //in case elms match but are unordered, i will not get to end of a
            if (i!=a.size()) ans = 0;
        }
        return ans;
    }
};

int main()
{
    Solution q;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> pieces = {{3, 4}, {2}, {5}, {1}};
    cout << q.canFormArray(arr, pieces) << endl;
}