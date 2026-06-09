// Last updated: 09/06/2026, 19:44:13
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();

        int mx=0;
        for(int x:nums)mx=max(mx,x);

        int lim=1;
        while(lim<=mx)lim<<=1;
        lim<<=1;

        vector<int>dp(lim,-1e9);
        dp[0]=0;

        for(int num:nums){
            vector<int>ndp=dp;
            for(int x=0;x<lim;x++){
                if(dp[x]<0)continue;
                ndp[x^num]=max(ndp[x^num],dp[x]+1);
            }
            dp=ndp;
        }

        if(target>=lim || dp[target]<0)return -1;

        return n-dp[target];
    }
};