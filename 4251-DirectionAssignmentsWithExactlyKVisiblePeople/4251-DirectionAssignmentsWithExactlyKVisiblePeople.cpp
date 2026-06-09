// Last updated: 09/06/2026, 19:43:11
class Solution {
public:
    int mod=1e9+7;
    long long power(long long a,long long b){
        long long res=1;

        while(b){
            if(b&1)res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }

    long long ncr(int n,int r,vector<long long>&fact,vector<long long>&invfact){
        if(r<0||r>n)return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }
    
    int countVisiblePeople(int n, int pos, int k) {
        int l=pos;
        int r=n-pos-1;

        vector<long long>fact(n+1),invfact(n+1);

        fact[0]=1;

        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1]*i%mod;
        }

        invfact[n]=power(fact[n],mod-2);

        for(int i=n-1;i>=0;i--){
            invfact[i]=invfact[i+1]*(i+1)%mod;
        }

        long long ans=ncr(n-1,k,fact,invfact);

        // for(int x=max(0,k-r);k<=min(k,l);x++){
        //     long long left=ncr(l,x,fact,invfact);
        //     long long right=ncr(r,k-x,fact,invfact);

        //     ans=(ans+left*right%mod)%mod;
        // }

        ans=(ans*2)%mod;

        return (int)ans;
    }
};