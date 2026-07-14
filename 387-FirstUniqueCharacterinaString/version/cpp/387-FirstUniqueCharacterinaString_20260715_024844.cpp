// Last updated: 15/07/2026, 02:48:44
1class Solution {
2public:
3    int countDigits(int num) {
4        string s=to_string(num);
5
6        int ans=0;
7        for(int i=0;i<s.size();i++){
8
9            int p=s[i]-'0';
10            if(num%p==0)ans++;
11        }
12        return ans;
13    }
14};