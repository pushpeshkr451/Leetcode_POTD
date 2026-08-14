// Last updated: 15/08/2026, 02:55:19
1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        vector<int> check = nums;
5
6        reverse(check.begin(), check.end());
7
8        if (is_sorted(check.begin(), check.end())) {
9            sort(nums.begin(), nums.end());
10            return;
11        } else {
12            int n = nums.size();
13            int i = n - 1;
14            int idx = -1;
15
16            while (i >= 1) {
17                if (nums[i - 1] < nums[i]) {
18                    idx = i - 1;
19                    break;
20                }
21                i--;
22            }
23            idx++;
24
25            int val = INT_MAX, val_idx = -1;
26            int j = n - 1;
27
28            while (nums[j] <= nums[i - 1])
29                j--;
30
31            swap(nums[i - 1], nums[j]);
32            reverse(nums.begin() + i, nums.end());
33        }
34    }
35};