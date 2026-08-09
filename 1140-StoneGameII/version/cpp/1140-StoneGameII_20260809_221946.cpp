// Last updated: 09/08/2026, 22:19:46
1class Solution {
2public:
3    int n;
4    vector<int> suffix;
5    vector<vector<int>> dp;
6
7    int solve(int i, int M) {
8        if (i == n) {
9            return 0;
10        }
11
12        if (dp[i][M] != -1) {
13            return dp[i][M];
14        }
15
16        int best = 0;
17
18        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
19            int nextM = max(M, X);
20            int current = suffix[i] - solve(i + X, nextM);
21            best = max(best, current);
22        }
23
24        return dp[i][M] = best;
25    }
26
27    int stoneGameII(vector<int>& piles) {
28        n = piles.size();
29
30        suffix.assign(n + 1, 0);
31        for (int i = n - 1; i >= 0; i--) {
32            suffix[i] = suffix[i + 1] + piles[i];
33        }
34
35        dp.assign(n, vector<int>(n + 1, -1));
36
37        return solve(0, 1);
38    }
39};