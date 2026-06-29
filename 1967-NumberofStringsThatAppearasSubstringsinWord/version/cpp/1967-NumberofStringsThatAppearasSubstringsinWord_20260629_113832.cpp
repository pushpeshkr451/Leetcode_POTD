// Last updated: 29/06/2026, 11:38:32
1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int ans = 0;
5
6        for (string &s : patterns) {
7            if (word.find(s) != string::npos)
8                ans++;
9        }
10
11        return ans;
12    }
13};