// Last updated: 15/07/2026, 03:32:30
1class Solution {
2public:
3    int countKeyChanges(string s) {
4        int ans=0;
5        char pre;
6        if(isupper(s[0]))pre=s[0]-'A';
7        else pre=s[0]-'a';
8
9        for(int i=1;i<s.size();i++){
10            char ch;
11            if(isupper(s[i])){
12                ch=s[i]-'A';
13            }
14            else ch=s[i]-'a';
15            if(ch!=pre)ans++;
16            pre=ch;
17        }
18
19        return ans;
20    }
21};