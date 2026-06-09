// Last updated: 09/06/2026, 19:43:25
class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())) return 0;

        int n=s.size();
        if(n==2) return -1;

        string t=s;
        sort(t.begin(),t.end());

        if(s[0]==t[0] || s[n-1]==t[n-1]) return 1;

        if(s[0]==t[n-1] && s[n-1]==t[0] && t[0]!=t[1] && t[n-1]!=t[n-2]) 
            return 3;

        return 2;
    }
};