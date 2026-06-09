// Last updated: 09/06/2026, 19:43:52
class Solution {
public:
    int minFlips(string s) {
        const int INF=1e9;

        vector<int>dp(16,INF),ndp(16,INF);
        dp[0]=0;

        for(char ch:s){
            fill(ndp.begin(),ndp.end(),INF);

            for(int mask=0;mask<16;mask++){
                if(dp[mask]==INF)continue;

                int has0=(mask>>0)&1;
                int has1=(mask>>1)&1;
                int has01=(mask>>2)&1;
                int has11=(mask>>3)&1;

                for(int b=0;b<=1;b++){
                    if(b==1 && has01)continue;
                    if(b==0 && has11)continue;

                    int n0=has0;
                    int n1=has1;
                    int n01=has01;
                    int n11=has11;

                    if(b==0)n0=1;
                    else{
                        n1=1;
                        if(has0)n01=1;
                        if(has1)n11=1;
                    }

                    int nmask=n0|(n1<<1)|(n01<<2)|(n11<<3);

                    ndp[nmask]=min(ndp[nmask],dp[mask]+(b!=(ch-'0')));
                }
            }
            dp=ndp;
        }
        int ans=INF;

        for(int x:dp)ans=min(ans,x);

        return ans;
    }
};