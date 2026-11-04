// Last updated: 04/11/2026, 09:06:51
1
2class Solution {
3public:
4
5    vector<long long> table(vector<int>& nums, int n, int x) {
6        vector<long long> output(n - x + 1);
7
8        multiset<int> lower;
9        multiset<int> upper;
10
11        long long LSUM = 0;
12        long long USUM = 0;
13
14        for (int i = 0; i < n; i++) {
15            int val = nums[i];
16            if (lower.empty() || val <= (*lower.rbegin())) {
17                lower.insert(val);
18                LSUM += val;
19            } else {
20                upper.insert(val);
21                USUM += val;
22            }
23
24            if (i - x >= 0) {
25                int rem = nums[i - x];
26                if (rem <= (*lower.rbegin())) {
27                    LSUM -= rem;
28                    lower.erase(lower.find(rem));
29                } else {
30                    USUM -= rem;
31                    upper.erase(upper.find(rem));
32                }
33            }
34
35            while (upper.size() > lower.size()) {
36                int balance = (*upper.begin());
37                USUM -= balance;
38                LSUM += balance;
39                upper.erase(upper.find(balance));
40                lower.insert(balance);
41            }
42            while (upper.size() + 1 < lower.size()) {
43                int balance = (*lower.rbegin());
44                USUM += balance;
45                LSUM -= balance;
46                upper.insert(balance);
47                lower.erase(lower.find(balance));
48            }
49
50            if (i + 1 >= x) {
51                int median = *(lower.rbegin());
52                long long UDIST = (upper.empty()) ? 0 : (USUM - (long long)upper.size() * median);
53                long long LDIST = (lower.empty()) ? 0 : ((long long)lower.size() * median - LSUM);
54                output[i - x + 1] = UDIST + LDIST;
55            }   
56        }
57
58        return output;
59    }
60
61    long long minOperations(vector<int>& nums, int x, int k) {
62        int n = (int)nums.size();
63
64        vector<long long> tb = table(nums, n, x);
65        vector<vector<long long>> DP(n + 1, vector<long long>(k + 1));
66
67        for (int i = 1; i <= n; i++) {
68            for (int k_p = 1; k_p <= k; k_p++) {
69                if (k_p * x > i) {
70                    DP[i][k_p] = LLONG_MAX;
71                    continue;
72                }
73
74                long long cost = tb[i - x];
75                DP[i][k_p] = min(DP[i - 1][k_p], cost + DP[i - x][k_p - 1]);
76            }
77        }
78
79        long long answer = LLONG_MAX;
80
81        for (int i = 1; i <= n; i++) answer = min(answer, DP[i][k]);
82
83        return answer;
84    }
85};