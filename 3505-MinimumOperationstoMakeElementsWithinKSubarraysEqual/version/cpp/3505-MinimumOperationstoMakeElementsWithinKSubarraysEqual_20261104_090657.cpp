// Last updated: 04/11/2026, 09:06:57
1
2class Solution {
3public:
4    vector<long long> table(vector<int>& nums, int n, int x) {
5        vector<long long> output(n - x + 1);
6
7        multiset<int> lower;
8        multiset<int> upper;
9
10        long long LSUM = 0;
11        long long USUM = 0;
12
13        for (int i = 0; i < n; i++) {
14            int val = nums[i];
15            if (lower.empty() || val <= (*lower.rbegin())) {
16                lower.insert(val);
17                LSUM += val;
18            } else {
19                upper.insert(val);
20                USUM += val;
21            }
22
23            if (i - x >= 0) {
24                int rem = nums[i - x];
25                if (rem <= (*lower.rbegin())) {
26                    LSUM -= rem;
27                    lower.erase(lower.find(rem));
28                } else {
29                    USUM -= rem;
30                    upper.erase(upper.find(rem));
31                }
32            }
33
34            while (upper.size() > lower.size()) {
35                int balance = (*upper.begin());
36                USUM -= balance;
37                LSUM += balance;
38                upper.erase(upper.find(balance));
39                lower.insert(balance);
40            }
41            while (upper.size() + 1 < lower.size()) {
42                int balance = (*lower.rbegin());
43                USUM += balance;
44                LSUM -= balance;
45                upper.insert(balance);
46                lower.erase(lower.find(balance));
47            }
48
49            if (i + 1 >= x) {
50                int median = *(lower.rbegin());
51                long long UDIST =
52                    (upper.empty()) ? 0
53                                    : (USUM - (long long)upper.size() * median);
54                long long LDIST =
55                    (lower.empty()) ? 0
56                                    : ((long long)lower.size() * median - LSUM);
57                output[i - x + 1] = UDIST + LDIST;
58            }
59        }
60
61        return output;
62    }
63
64    long long minOperations(vector<int>& nums, int x, int k) {
65        int n = (int)nums.size();
66
67        vector<long long> tb = table(nums, n, x);
68        vector<vector<long long>> DP(n + 1, vector<long long>(k + 1));
69
70        for (int i = 1; i <= n; i++) {
71            for (int k_p = 1; k_p <= k; k_p++) {
72                if (k_p * x > i) {
73                    DP[i][k_p] = LLONG_MAX;
74                    continue;
75                }
76
77                long long cost = tb[i - x];
78                DP[i][k_p] = min(DP[i - 1][k_p], cost + DP[i - x][k_p - 1]);
79            }
80        }
81
82        long long answer = LLONG_MAX;
83
84        for (int i = 1; i <= n; i++)
85            answer = min(answer, DP[i][k]);
86
87        return answer;
88    }
89};