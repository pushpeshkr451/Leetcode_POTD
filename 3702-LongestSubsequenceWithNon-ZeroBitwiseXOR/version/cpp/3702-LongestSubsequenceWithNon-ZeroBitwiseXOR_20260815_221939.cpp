// Last updated: 15/08/2026, 22:19:39
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int n = nums.size();
5        int i = 0, j = 0;
6
7        int cnt = 0;
8
9        while (j < n) {
10            cnt ^= nums[j];
11            j++;
12        }
13
14        if (cnt == 0) {
15            while (i < n && nums[i] == 0)
16                i++;
17            if (i == n)
18                return 0;
19            return n - 1;
20        } else
21            return n;
22    }
23};