// Last updated: 15/07/2026, 15:29:30
1class Solution {
2public:
3    int largestSumAfterKNegations(vector<int>& nums, int k) {
4
5        sort(nums.begin(), nums.end());
6
7        for (int i = 0; i < nums.size() && k > 0; i++) {
8            if (nums[i] < 0) {
9                nums[i] = -nums[i];
10                k--;
11            }
12        }
13
14        int sum = 0;
15        int mn = INT_MAX;
16
17        for (int x : nums) {
18            sum += x;
19            mn = min(mn, abs(x));
20        }
21
22        if (k % 2 == 1)
23            sum -= 2 * mn;
24
25        return sum;
26    }
27};