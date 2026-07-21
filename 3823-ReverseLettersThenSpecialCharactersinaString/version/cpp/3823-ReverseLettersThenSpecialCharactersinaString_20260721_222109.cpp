// Last updated: 21/07/2026, 22:21:09
1class Solution {
2public:
3    string reverseByType(string s) {
4        string lo = "", spec = "";
5
6        for (int i = 0; i < s.size(); i++) {
7            if (islower(s[i]))
8                lo += s[i];
9            else
10                spec += s[i];
11        }
12
13        // cout<<lo<<" "<<spec;
14        reverse(lo.begin(), lo.end());
15        reverse(spec.begin(), spec.end());
16
17        int i = 0, j = 0;
18        string ans = "";
19        for (int k = 0; k < s.size(); k++) {
20            if (islower(s[k])) {
21
22                ans += lo[i];
23                i++;
24            } else {
25                ans += spec[j];
26                j++;
27            }
28        }
29        return ans;
30    }
31};