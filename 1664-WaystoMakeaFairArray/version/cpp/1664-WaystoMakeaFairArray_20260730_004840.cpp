// Last updated: 30/07/2026, 00:48:40
1class Solution {
2public:
3    int waysToMakeFair(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int tote = 0, toto = 0;
8
9        for (int i = 0; i < n; i++) {
10            if (i % 2)
11                toto += nums[i];
12            else
13                tote += nums[i];
14        }
15
16        int pree = 0, preo = 0;
17        int ans = 0;
18
19        for (int i = 0; i < n; i++) {
20
21            int re = tote - pree;
22            int ro = toto - preo;
23
24            if (i % 2 == 0)
25                re -= nums[i];
26            else
27                ro -= nums[i];
28
29            int ne = pree + ro;
30            int no = preo + re;
31
32            if (ne == no)
33                ans++;
34
35            if (i % 2)
36                preo += nums[i];
37            else
38                pree += nums[i];
39        }
40
41        return ans;
42    }
43};