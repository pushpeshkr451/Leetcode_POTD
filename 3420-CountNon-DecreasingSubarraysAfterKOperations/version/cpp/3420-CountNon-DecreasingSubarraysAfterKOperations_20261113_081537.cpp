// Last updated: 13/11/2026, 08:15:37
1class Solution {
2public:
3    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
4        const int N = nums.size();
5
6        vector<int> next_ge(
7            N, N); // Where nums[nums[i]] >= nums[i]; N means no GE forward
8        vector<int> desc_stk; // Monotonic stack to find next GE
9        for (int i = 0; i < N; ++i) {
10            while (desc_stk.size() && nums[desc_stk.back()] <= nums[i]) {
11                next_ge[desc_stk.back()] = i;
12                desc_stk.pop_back();
13            }
14            desc_stk.push_back(i);
15        }
16
17        long long res = 0;
18
19        long long rem_ops = k; // Remaining operations allowed
20        for (int beg = 0, end = 0, max_window = nums[0]; beg < N; ++beg) {
21            if (beg == end)
22                max_window = nums[end]; // Reset window max
23
24            // Sliding window consider how far end can go begind beg
25            for (; end < N && rem_ops >= 0; ++end) {
26                max_window = max(max_window, nums[end]);
27                const int cost = max_window - nums[end];
28                if (cost > rem_ops)
29                    break;
30                rem_ops -= cost;
31            }
32            res += end - beg;
33
34            // Release operations for outgoing `beg`
35            int local_max =
36                beg + 1 < N ? nums[beg + 1] : 0; // Local max after beg + 1
37            for (int i = beg + 1, j = -1; i < end && nums[i] < nums[beg];
38                 i = j) {
39                // Release rem_ops for elements [i..j)
40                j = next_ge[i];
41                if (j < end)
42                    local_max = max(local_max, nums[j]);
43                int top = j < end ? min(nums[beg], nums[j]) : nums[beg];
44                long long height = top - nums[i];
45                long long width = min(j, end) - beg - 1;
46                rem_ops += height * width; // Release: (nums[i]..top] X [i..j)
47                if (j >= end)
48                    max_window = local_max;
49            }
50        }
51
52        return res;
53    }
54};