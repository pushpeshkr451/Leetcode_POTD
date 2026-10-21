// Last updated: 21/10/2026, 13:21:01
1class Solution {
2public:
3    int minOperations(string s) {
4        if(is_sorted(s.begin(),s.end())) return 0;
5
6        int n=s.size();
7        if(n==2) return -1;
8
9        string t=s;
10        sort(t.begin(),t.end());
11
12        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;
13
14        if(s[0]==t[n-1] && s[n-1]==t[0] && t[0]!=t[1] && t[n-1]!=t[n-2]) 
15            return 3;
16
17        return 2;
18    }
19};