// Last updated: 08/07/2026, 21:38:55
1class Solution {
2public:
3    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
4        const int MOD = 1e9 + 7;
5        int n = s.size();
6
7        vector<long long> pow10(n + 1, 1);
8        for (int i = 1; i <= n; i++)
9            pow10[i] = (pow10[i - 1] * 10) % MOD;
10
11        // idx[i] = number of non-zero digits before index i
12        vector<int> idx(n + 1, 0);
13
14        // val[i] = number formed by first i non-zero digits
15        vector<long long> val(n + 1, 0);
16
17        // total[i] = sum of first i non-zero digits
18        vector<long long> total(n + 1, 0);
19
20        int cnt = 0;
21
22        for (int i = 0; i < n; i++) {
23            int digit = s[i] - '0';
24
25            if (digit != 0) {
26                cnt++;
27
28                val[cnt] = (val[cnt - 1] * 10 + digit) % MOD;
29                total[cnt] = total[cnt - 1] + digit;
30            }
31
32            idx[i + 1] = cnt;
33        }
34
35        vector<int> ans;
36
37        for (auto &q : queries) {
38
39            int l = q[0];
40            int r = q[1];
41
42            int left = idx[l];
43            int right = idx[r + 1];
44            //no non-zero digit in the range
45            if (left == right) { 
46                ans.push_back(0);
47                continue;
48            }
49
50            int len = right - left;
51
52            long long number =(val[right] - val[left] * pow10[len]) % MOD;
53
54            if (number < 0)
55                number += MOD;
56
57            long long sum = total[right] - total[left];
58            ans.push_back((number * sum) % MOD);
59        }
60
61        return ans;
62    }
63};