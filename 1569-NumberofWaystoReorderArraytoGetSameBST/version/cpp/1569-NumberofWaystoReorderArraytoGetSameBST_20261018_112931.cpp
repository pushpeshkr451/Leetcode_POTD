// Last updated: 18/10/2026, 11:29:31
1class Solution {
2public:
3    vector<vector<long long>> ncr;
4    long long mod = 1e9 + 7;
5    long long ways(vector<int>& v, int n) {
6        if (n <= 2)
7            return 1;
8        vector<int> left, right;
9        for (int i = 1; i < n; i++) {
10            if (v[0] > v[i])
11                left.push_back(v[i]);
12            else
13                right.push_back(v[i]);
14        }
15        long long ans_left = ways(left, left.size());
16        long long ans_right = ways(right, right.size());
17
18        long long ans =
19            (((ncr[n - 1][left.size()] * ans_left) % mod) * ans_right) % mod;
20        return ans;
21    }
22    int numOfWays(vector<int>& v) {
23        int n = v.size();
24        ncr.resize(n + 1);
25        for (int i = 0; i < n + 1; ++i) {
26            ncr[i] = vector<long long>(i + 1, 1);
27            for (int j = 1; j < i; ++j) {
28                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
29            }
30        }
31
32        return (ways(v, n) - 1) % mod;
33    }
34};