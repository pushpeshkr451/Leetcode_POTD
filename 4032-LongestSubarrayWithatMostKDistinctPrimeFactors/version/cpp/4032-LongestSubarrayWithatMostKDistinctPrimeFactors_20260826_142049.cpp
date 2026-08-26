// Last updated: 26/08/2026, 14:20:49
1class Solution {
2public:
3    string find_ascii(int n) {
4        string value = "";
5
6        for (int i = 7; i >= 0; i--) {
7            if (n & (1 << i))
8                value += '1';
9            else
10                value += '0';
11        }
12
13        return value;
14    }
15
16    bool isPalindromic(string s) {
17        string check = "";
18
19        for (auto it : s) {
20            int val = (int)it;
21            check += find_ascii(val);
22        }
23
24        string ans = check;
25        reverse(check.begin(), check.end());
26
27        return check == ans;
28    }
29};