// Last updated: 22/10/2026, 06:04:49
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int n = nums.size();
5        int z = 0;
6
7        for (int i = 0; i < n; i++) {
8            if (nums[i] == 0) {
9                z = i;
10                break;
11            }
12        }
13
14        bool inc = true, dec = true;
15
16        for (int i = 0; i < n; i++) {
17            if (nums[(z + i) % n] != i)
18                inc = false;
19            if (nums[(z + i) % n] != (n - i) % n)
20                dec = false;
21        }
22
23        if (!inc && !dec)
24            return -1;
25
26        int ans = 2e9;
27
28        if (inc) {
29            int p = (n - z) % n;
30            if (p == 0)
31                ans = min(ans, 0);
32            else
33                ans = min(ans, min(n - p, p + 2));
34        }
35
36        if (dec) {
37            int p = n - 1 - z;
38            ans = min(ans, min(p + 1, n - p + 1));
39        }
40
41        return ans;
42    }
43};