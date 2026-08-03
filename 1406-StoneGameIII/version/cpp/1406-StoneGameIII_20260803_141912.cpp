// Last updated: 03/08/2026, 14:19:12
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        int n = stoneValue.size();
5        vector<int> dp(n + 1, 0);
6
7        for (int i = n - 1; i >= 0; i--) {
8
9            int best = INT_MIN;
10            int runningSum = 0;
11
12            for (int k = 1; k <= 3; k++) {
13
14                if (i + k > n)
15                    break;
16
17                runningSum += stoneValue[i + k - 1];
18                best = max(best, runningSum - dp[i + k]);
19            }
20
21            dp[i] = best;
22        }
23
24        if (dp[0] > 0)
25            return "Alice";
26        else if (dp[0] < 0)
27            return "Bob";
28        else
29            return "Tie";
30    }
31};