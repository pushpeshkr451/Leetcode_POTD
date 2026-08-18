// Last updated: 18/08/2026, 14:10:32
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int ans = 0;
5
6        unordered_map<int, int> mp;
7        mp[0] = 1;
8
9        int sum = 0;
10
11        for (auto it : nums) {
12            sum += it;
13
14            int rem = sum - k;
15
16            if (mp.find(rem) != mp.end()) {
17                ans += mp[rem];
18            }
19
20            mp[sum]++;
21        }
22
23        return ans;
24    }
25};