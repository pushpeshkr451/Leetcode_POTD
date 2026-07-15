// Last updated: 15/07/2026, 15:27:52
1class Solution {
2public:
3    int largestSumAfterKNegations(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int p = k;
6        int n = nums.size();
7        int i = 0;
8        int cnt = INT_MAX;
9        if (nums[0] > 0) {
10            if (k % 2 == 1) {
11                nums[0] = -1 * nums[0];
12                return accumulate(nums.begin(), nums.end(), 0);
13            } else
14                return accumulate(nums.begin(), nums.end(), 0);
15        }
16
17        else {
18            int count = 0;
19            bool flag = false;
20            while (k-- && i < nums.size()) {
21                if (nums[i] == 0) {
22                    flag = true;
23                    break;
24                }
25                if (nums[i] < 0) {
26                    count++;
27                    nums[i] = -1 * nums[i];
28                }
29
30                cnt = min(cnt, nums[i]);
31                i++;
32            }
33            for (auto it : nums)
34                cout << it << " ";
35            if (flag)
36                return accumulate(nums.begin(), nums.end(), 0);
37            else if (count < p && (p - count) % 2 == 1)
38                return accumulate(nums.begin(), nums.end(), 0) - 2 * cnt;
39            return accumulate(nums.begin(), nums.end(), 0);
40        }
41    }
42};