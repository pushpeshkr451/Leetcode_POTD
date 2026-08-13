// Last updated: 13/08/2026, 22:30:13
1class Solution {
2public:
3    vector<int> searchRange(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        int lo = 0, hi = n - 1;
7        int idx1 = -1, idx2 = -1;
8
9        bool flag = false;
10
11        while (lo <= hi) {
12            int mid = lo + (hi - lo) / 2;
13            if (nums[mid] == target) {
14                flag = true;
15                hi = mid - 1;
16            } else if (nums[mid] < target)
17                lo = mid + 1;
18            else
19                hi = mid - 1;
20        }
21
22        if (flag)
23            idx1 = hi + 1;
24        lo = 0, hi = n - 1;
25        flag = false;
26
27        while (lo <= hi) {
28            int mid = lo + (hi - lo) / 2;
29
30            if (nums[mid] == target) {
31                flag = true;
32                lo = mid + 1;
33            } else if (nums[mid] < target)
34                lo = mid + 1;
35            else
36                hi = mid - 1;
37        }
38        if (flag)
39            idx2 = lo - 1;
40
41        return {idx1, idx2};
42    }
43};