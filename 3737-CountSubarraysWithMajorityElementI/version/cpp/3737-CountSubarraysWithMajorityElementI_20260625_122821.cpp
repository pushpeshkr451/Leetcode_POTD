// Last updated: 25/06/2026, 12:28:21
1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        int ans = 0;
6        for (int i = 0; i < n; ++i) {
7            int cnt = 0;
8            for (int j = i; j < n; ++j) {
9                cnt += (nums[j] == target ? 1 : -1);
10                if (cnt > 0) {
11                    ++ans;
12                }
13            }
14        }
15        return ans;
16    }
17};