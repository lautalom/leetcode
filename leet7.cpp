#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        vector<int> v;
        int z;
        int i = 0;
        bool pos = x > 0 ? 1 : 0;
        while (abs(x) > 0)
        {
            z = x % 10;
            x /= 10;
            i++;
            v.push_back(z);
        }
        z = 0;
        for (auto &a : v)
        {
            if (z < (INT32_MAX - a * pow(10, --i)) && z > (INT32_MIN - a * pow(10, i)))
                z += a * pow(10, i);
            else
                return 0;
        }
        cout << z << endl;
        return z;
    }
};

/////best runtime 
class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x!=0){
            rev = (rev*10)+(x%10);
            x /= 10;
        }
        if(rev<INT_MIN||rev>INT_MAX){
            return 0;
        }
        return rev;
    }
};

int main()
{
    int x = -1563847412;
    Solution q;
    q.reverse(x);
    return 0;
}