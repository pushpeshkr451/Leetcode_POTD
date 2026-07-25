// Last updated: 25/07/2026, 14:22:10
1class Solution {
2public:
3    int maxProduct(int n) {
4        string s=to_string(n);
5        sort(s.begin(),s.end());
6        int p=s.size();
7        return (s[p-1]-'0')*(s[p-2]-'0');
8    }
9};