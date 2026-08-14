// Last updated: 14/08/2026, 12:58:00
1class Solution {
2public:
3    void duplicateZeros(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6
7        for (int i = 0; i < n; i++) {
8            if (nums[i] == 0) {
9                ans.push_back(0);
10                if (ans.size() < n)
11                    ans.push_back(0);
12            }
13            else {
14                ans.push_back(nums[i]);
15            }
16
17            if (ans.size() == n)
18                break;
19        }
20
21        nums = ans;
22    }
23};