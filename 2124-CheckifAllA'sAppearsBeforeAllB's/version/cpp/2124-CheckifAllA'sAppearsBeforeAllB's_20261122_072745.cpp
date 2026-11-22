// Last updated: 22/11/2026, 07:27:45
1class Solution {
2public:
3    bool checkString(string s) {
4        for (int i = 1; i < s.size(); i++) {
5            if (s[i - 1] == 'b' && s[i] == 'a') {
6                return false;
7            }
8        }
9        return true;
10    }
11};