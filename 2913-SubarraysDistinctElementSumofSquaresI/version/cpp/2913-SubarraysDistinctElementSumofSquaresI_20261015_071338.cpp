// Last updated: 15/10/2026, 07:13:38
1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        int n = nums.size(),id{};
5        int sum{};
6        vector<int> fr(101);
7        for (int l = 0; l < n; l++) {
8            int cnt{};
9            id++;
10            for (int r = l; r < n; r++) {
11                cnt += (fr[nums[r]] != id);
12                fr[nums[r]] = id;
13                sum += pow(cnt, 2);
14            }
15        }
16        return sum;
17    }
18};