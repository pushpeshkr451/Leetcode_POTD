// Last updated: 18/08/2026, 13:22:00
1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int n = nums.size();
5        if(n==1)return 0;
6
7        vector<int> pref(n), suff(n);
8
9        pref[0] = nums[0];
10        suff[n - 1] = nums[n - 1];
11
12        for (int i = 1; i < n; i++)
13            pref[i] = pref[i - 1] + nums[i];
14
15        for (int i = n - 2; i >= 0; i--) {
16            suff[i] = suff[i + 1] + nums[i];
17        }
18
19        for (int i = 0; i < n; i++) {
20            if (i == 0 && n > 1) {
21                if (suff[i + 1] == 0)
22                    return 0;
23            } else if (i == n - 1 && n > 1) {
24                if (pref[n - 2] == 0)
25                    return n - 1;
26            } else if (pref[i - 1] == suff[i + 1])
27                return i;
28        }
29
30        return -1;
31    }
32};