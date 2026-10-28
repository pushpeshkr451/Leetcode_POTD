// Last updated: 28/10/2026, 20:30:22
1class Solution {
2public:
3    long long dp[100001][2];
4    long long lb(int ind, int end, vector<vector<int>>& meetings) {
5        int low = ind, high = meetings.size() - 1;
6        int ans = meetings.size();
7        while (low <= high) {
8            int mid = (low + high) / 2;
9            int s = meetings[mid][0];
10            if (s >= end) {
11                ans = mid;
12                high = mid - 1;
13            } else
14                low = mid + 1;
15        }
16        return ans;
17    }
18    long long solve(int i, bool flag, vector<vector<int>>& meetings) {
19        int n = meetings.size();
20        if (i >= n)
21            return 0;
22        if (dp[i][flag] != -1)
23            return dp[i][flag];
24        int r = meetings[i][2];
25        int e = meetings[i][1];
26        // find lower bound
27        int j = lb(i, e, meetings);
28        long long take = r - e + solve(j, true, meetings);
29        if (j == n)
30            take = r;
31        if (flag)
32            take += meetings[i][0];
33        long long skip = solve(i + 1, flag, meetings);
34        return dp[i][flag] = max(take, skip);
35    }
36    long long maxEarnings(vector<vector<int>>& meetings) {
37        sort(meetings.begin(), meetings.end());
38        memset(dp, -1, sizeof(dp));
39        // flag->
40        // if it is the first meeting then dont add start time
41        // else add
42        return solve(0, 0, meetings);
43    }
44};