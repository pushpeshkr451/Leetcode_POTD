// Last updated: 15/07/2026, 02:45:11
1class Solution {
2public:
3    int mostWordsFound(vector<string>& s) {
4        int ans=INT_MIN;
5
6        for(int i=0;i<s.size();i++){
7            int cnt=0;
8
9            for(int j=0;j<s[i].size();j++){
10                if(s[i][j]==' ')cnt++;
11            }
12            ans=max(ans,cnt);
13        }
14
15        return ans+1;
16    }
17};