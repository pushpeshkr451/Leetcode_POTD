// Last updated: 18/08/2026, 12:50:24
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4
5        int n = nums.size();
6
7        unordered_map<int, int> mp;
8
9        for (int i = 0; i <= n - k; i++) {
10
11            unordered_set<int> st;
12
13            for (int j = i; j < i + k; j++) {
14                st.insert(nums[j]);
15            }
16
17            for (int x : st) {
18                mp[x]++;
19            }
20        }
21
22        int ans = -1;
23
24        for (auto it : mp) {
25            if (it.second == 1) {
26                ans = max(ans, it.first);
27            }
28        }
29
30        return ans;
31    }
32};