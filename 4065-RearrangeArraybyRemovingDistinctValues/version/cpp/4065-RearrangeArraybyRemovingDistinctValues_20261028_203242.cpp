// Last updated: 28/10/2026, 20:32:42
1class Solution {
2public:
3    vector<int> rearrangeArray(vector<int>& nums) {
4        unordered_map<int, int> mp;
5        vector<int> ans;
6        sort(nums.begin(), nums.end());
7        int mx = 0;
8        for (auto it : nums) {
9            mp[it]++;
10            mx = max(mx, mp[it]);
11        }
12        for (int i = 0; i < mx; i++) {
13            for (int j = 0; j < nums.size(); j++) {
14                if (mp[nums[j]] > 0) {
15                    if (j == 0 or nums[j] != nums[j - 1]) {
16                        ans.push_back(nums[j]);
17                        mp[nums[j]]--;
18                    }
19                }
20            }
21        }
22        return ans;
23    }
24};