// Last updated: 02/10/2026, 09:47:16
1class Solution {
2public:
3    void solve(int open, int close, string cur, vector<string>& ans) {
4        if (open == 0 && close == 0) {
5            ans.push_back(cur);
6        } else if (open == 0) {
7            solve(open, close - 1, cur + ')', ans);
8        } else if (open < close) {
9            solve(open, close - 1, cur + ')', ans);
10            solve(open - 1, close, cur + '(', ans);
11            return;
12        } else {
13            solve(open - 1, close, cur + '(', ans);
14        }
15    }
16
17    vector<string> generateParenthesis(int n) {
18        vector<string> ans;
19        solve(n, n, "", ans);
20        return ans;
21    }
22};