// Last updated: 09/06/2026, 19:43:12
class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;

        long long ans=0;

        for(int d=4;d<=16;d++){
            long long l=pow(10,d-1);

            if(l>n)break;
            long long r=min(n,(long long)pow(10,d)-1);

            long long cnt=r-l+1;

            long long com=(d-1)/3;
            ans+=cnt*com;
        }
        return ans;
    }
};