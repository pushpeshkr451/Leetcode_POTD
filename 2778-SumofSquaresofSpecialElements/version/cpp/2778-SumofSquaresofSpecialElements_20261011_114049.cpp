// Last updated: 11/10/2026, 11:40:49
1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int n = nums.size();
5        if (n <= 0)
6            return 0;
7        int sum = 0;
8
9        for (int i = 1; i <= n; i++) {
10            if (n % i == 0) {
11                sum += nums[i - 1] * nums[i - 1];
12            }
13        }
14        return sum;
15    }
16};