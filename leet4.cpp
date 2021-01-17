
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double getMed(vector<int> a1, vector<int> a2, int n1, int n2)
    {
        int begin1 = 0, end1 = n1;

        while (begin1 <= end1)
        {
            int i1 = (begin1 + end1) / 2;
            int i2 = (n1 + n2 + 1) / 2 - i1;

            //a1 = [0,1,...max1|min1,...,n1-1]
            int min1 = (i1 == n1) ? INT_MAX : a1[i1];
            int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
            //a2 = [0,1,...max2|min2,...,n2-1]
            int min2 = (i2 == n2) ? INT_MAX : a2[i2];
            int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

            if (max1 <= min2 && max2 <= min1)
            {//we found the median!
                if ((n1 + n2) % 2 == 0)//case even sum
                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                else
                    return (double)max(max1, max2);
            }
            else if (max1 > min2)
                end1 = i1 - 1;
            else
                begin1 = i1 + 1;
        }

        return 0.0;
    }

    double isEmpty(vector<int> a1, vector<int> a2, int n1, int n2)
    {
        if (n1 == 0)
        {
            if (n2 % 2)
                return (double)(a2[n2 / 2]);
            else
                return (double)(a2[n2 / 2 - 1] + a2[n2 / 2]) / 2;
        }
        else
            return 0;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();

        double x = (double)0;
        //check if fst array is empty and return normal median within snd
        x = isEmpty(nums1, nums2, n1, n2);
        if (x != 0.0)
            return x;
        x = isEmpty(nums2, nums1, n2, n1);
        if (x != 0.0)
            return x;
        if (n1 < n2) //binary search on shorter array
            return getMed(nums1, nums2, n1, n2);
        else
            return getMed(nums2, nums1, n2, n1);
    }
};

int main()
{
    Solution q;
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    cout << q.findMedianSortedArrays(nums1, nums2) << endl;
}