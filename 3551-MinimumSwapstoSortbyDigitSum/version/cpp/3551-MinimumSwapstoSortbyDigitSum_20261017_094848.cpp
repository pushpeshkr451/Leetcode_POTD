// Last updated: 17/10/2026, 09:48:48
1class Solution {
2public:
3    int minSwaps(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<tuple<int, int, int>> vt;
7
8        for (int i = 0; i < n; i++) {
9            string s = to_string(nums[i]);
10            int sum = 0;
11            for (int j = 0; j < s.size(); j++)
12                sum += (s[j] - '0');
13            vt.push_back({sum, nums[i], i});
14        }
15
16        sort(vt.begin(), vt.end());
17
18        int swaps = 0;
19        for (int i = 0; i < n; i++) {
20            while (get<2>(vt[i]) != i) {
21                swap(vt[i], vt[get<2>(vt[i])]);
22                swaps++;
23            }
24        }
25        return swaps;
26    }
27};