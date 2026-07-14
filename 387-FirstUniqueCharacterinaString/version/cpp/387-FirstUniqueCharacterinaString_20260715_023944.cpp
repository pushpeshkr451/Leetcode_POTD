// Last updated: 15/07/2026, 02:39:44
1class Solution {
2public:
3    vector<int> numberGame(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> ans;
7        sort(nums.begin(), nums.end());
8        int i = 0, j = 1;
9        while (i < n && j < n) {
10            ans.push_back(nums[j]);
11            ans.push_back(nums[i]);
12            i += 2;
13            j += 2;
14        }
15
16        return ans;
17    }
18};