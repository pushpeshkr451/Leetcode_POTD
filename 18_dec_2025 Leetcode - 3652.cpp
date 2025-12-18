class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& st, int k) {
        int n=prices.size();
        vector<long long>presp(n+1,0),prep(n+1,0);
        for(int i=0;i<n;i++){
            presp[i+1]=presp[i]+1LL*st[i]*prices[i];
            prep[i+1]=prep[i]+prices[i];
        }
        long long org=presp[n];
        long long best=0;

        for(int l=0;l+k<=n;l++){
            int mid=l+k/2;
            int r=l+k;
            long long a=presp[r]-presp[l];
            long long b=prep[r]-prep[mid];

            long long c=b-a;
            best=max(best,c);
        }
        return org+best;
    }
};
