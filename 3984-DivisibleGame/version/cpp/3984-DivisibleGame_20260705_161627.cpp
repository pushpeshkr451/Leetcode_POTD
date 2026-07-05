// Last updated: 05/07/2026, 16:16:27
1class Solution {
2public:
3    long long getSum(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<long long> pref(n + 1);
7        for (int i = 0; i < n; i++)
8            pref[i + 1] = pref[i] + nums[i];
9
10        long long ans = 0;
11
12        vector<int> d1(n);
13        int l = 0, r = -1;
14
15        for (int i = 0; i < n; i++) {
16            int k;
17            if (i > r)
18                k = 1;
19            else
20                k = min(d1[l + r - i], r - i + 1);
21
22            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
23                k++;
24
25            d1[i] = k;
26
27            if (i + k - 1 > r) {
28                l = i - k + 1;
29                r = i + k - 1;
30            }
31
32            int left = i - d1[i] + 1;
33            int right = i + d1[i] - 1;
34
35            ans = max(ans, pref[right + 1] - pref[left]);
36        }
37
38        vector<int> d2(n);
39        l = 0;
40        r = -1;
41
42        for (int i = 0; i < n; i++) {
43            int k;
44
45            if (i > r)
46                k = 0;
47            else
48                k = min(d2[l + r - i + 1], r - i + 1);
49
50            while (i - k - 1 >= 0 && i + k < n &&
51                   nums[i - k - 1] == nums[i + k])
52                k++;
53
54            d2[i] = k;
55
56            if (i + k - 1 > r) {
57                l = i - k;
58                r = i + k - 1;
59            }
60
61            if (d2[i] > 0) {
62                int left = i - d2[i];
63                int right = i + d2[i] - 1;
64
65                ans = max(ans, pref[right + 1] - pref[left]);
66            }
67        }
68
69        return ans;
70    }
71};