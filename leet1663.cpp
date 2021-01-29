//Smallest String With A Given Numeric Value
#include <iostream>
#include <algorithm>
using namespace std;
//1 <= n <= 105
//n <= k <= 26 * n
const int N = 25;
class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        //minimum and optimal
        string ans(n, 'a');
        k -= n;
        //safety check to general solution, not compulsory by constraints
        if (k < 0 || n * 26 < k)
            return "";
        while (k > 0)
        {
            //fill with min(z,remainder) from the end down
            ans[--n] += min(N, k);
            k -= min(N, k);
        }
        return ans;
    }
};

int main()
{
    Solution q;
    cout << q.getSmallestString(3, 27) << endl;
    return 0;
}