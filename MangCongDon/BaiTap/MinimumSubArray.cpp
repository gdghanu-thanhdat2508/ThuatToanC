#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// You are given an integer array nums and two integers l and r.
// Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and
// whose sum is greater than 0.

// Return the minimum sum of such a subarray. If no such subarray exists, return -1.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        vector<int> F(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            F[i + 1] = F[i] + nums[i];
        }

        int minvalue = INT_MAX;

        for (int i = l; i <= r; i++)
        {
            for (int j = 0; j + i <= n; j++)
            {
                int sum = F[j + i] - F[j];
                if (sum > 0)
                {
                    minvalue = min(minvalue, sum);
                }
            }
        }

        if (minvalue == INT_MAX)
        {
            return -1;
        }
        return minvalue;
    }
};

int main()
{

    return 0;
}