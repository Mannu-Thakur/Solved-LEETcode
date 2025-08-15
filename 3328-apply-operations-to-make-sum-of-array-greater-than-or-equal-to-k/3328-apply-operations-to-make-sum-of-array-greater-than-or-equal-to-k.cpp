class Solution
{
public:
    int minOperations(int k)
    {
        int x = sqrt(k);
        return (x - 1 + (k - 1) / x);
    }
};