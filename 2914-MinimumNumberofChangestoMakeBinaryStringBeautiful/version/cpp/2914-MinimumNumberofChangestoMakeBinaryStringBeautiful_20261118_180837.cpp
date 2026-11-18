// Last updated: 18/11/2026, 18:08:37
1class Solution {
2public:
3    int minChanges(string s) {
4        int ans=0;
5        for(int i=0;i<s.size();i+=2){
6            if(s[i]==s[i+1]){
7                continue;
8            }
9            else{
10                ans++;
11            }
12        }
13        return ans;
14    }
15};