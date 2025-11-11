class Solution {
public:
int dp[105][105][605];
int solve(vector<string>& strs, int m, int n,int idx){
    if(idx==strs.size())return 0;
    if(dp[m][n][idx]!=-1)return dp[m][n][idx];
    int cnt0=0;
    for(auto it:strs[idx]){
        if(it=='0')cnt0++;
    }
    int cnt1=strs[idx].size()-cnt0;
    if(m-cnt0>=0 && n-cnt1>=0){
        int take=1+solve(strs,m-cnt0,n-cnt1,idx+1);
        int skip=solve(strs,m,n,idx+1);
        return dp[m][n][idx]=max(take,skip);
    }
    return  dp[m][n][idx]=solve(strs,m,n,idx+1);

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};
