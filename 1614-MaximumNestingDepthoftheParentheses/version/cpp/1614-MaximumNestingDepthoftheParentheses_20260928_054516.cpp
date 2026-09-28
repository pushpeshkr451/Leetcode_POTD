// Last updated: 28/09/2026, 05:45:16
1class Solution {
2public:
3    int maxDepth(string s) {
4        int cnt = 0, ans = 0;
5
6        for(char it : s) {
7            if(it == '(') cnt++;
8            else if(it == ')') cnt--;
9
10            ans = max(ans, cnt);
11        }
12
13        return ans;
14    }
15};