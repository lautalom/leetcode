class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long val = 0;
        int original = x;
        while (x)
        {
            val = 10 * val + x % 10;
            x /= 10;
        }
        return val == original;
    }
};