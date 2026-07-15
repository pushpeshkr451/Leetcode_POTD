// Last updated: 15/07/2026, 14:58:23
1class Solution {
2public:
3    int specialArray(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        int n = nums.size();
7
8        for (int i = 0; i <= n; i++) {
9            int lo = 0, hi = n - 1;
10
11            while (lo <= hi) {
12                int mid = lo + (hi - lo) / 2;
13
14                if (nums[mid] < i)
15                    lo = mid + 1;
16                else
17                    hi = mid - 1;
18            }
19
20            int cnt = n - lo;
21
22            if (cnt == i)
23                return i;
24        }
25
26        return -1;
27    }
28};