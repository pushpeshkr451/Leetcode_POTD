// Last updated: 06/07/2026, 12:51:40
1class Solution {
2public:
3    const int m = 1e9+7;
4    int dp[101][101][101];
5
6    int solve(string &w1,string &w2,string &target,int i,int j,int k){
7        if(k == target.size() && i>0 && j>0) return 1;
8
9        if(dp[i][j][k] != -1) return dp[i][j][k];
10
11        int ans = 0;
12
13        for(int p=i; p<w1.size(); p++){
14            if(w1[p] == target[k])
15                ans = (ans + solve(w1,w2,target,p+1,j,k+1)) % m;
16        }
17
18        for(int p=j; p<w2.size(); p++){
19            if(w2[p] == target[k])
20                ans = (ans + solve(w1,w2,target,i,p+1,k+1)) % m;
21        }
22
23        return dp[i][j][k] = ans;
24    }
25
26    int interleaveCharacters(string w1, string w2, string target) {
27        memset(dp,-1,sizeof(dp));
28        return solve(w1,w2,target,0,0,0);
29    }
30};