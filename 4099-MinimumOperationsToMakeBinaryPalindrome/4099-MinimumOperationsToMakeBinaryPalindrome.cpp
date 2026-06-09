// Last updated: 09/06/2026, 19:44:11
class Solution {
public:

    long long revbits(long long x,int bits){
        long long r=0;
        for(int i=0;i<bits;i++){
            r=(r<<1)|(x&1);
            x>>=1;
        }
        return r;
    }
    long long makepal(int len,long long prefix){
        if(len==1)return prefix&1;

        int half=(len+1)/2;
        if(len%2==0){
            int ha=len/2;
            long long low=revbits(prefix,ha);
            return (prefix<<ha)|low;
        }
        else{
            long long high=prefix;
            long long low=revbits(prefix>>1,half-1);
            return (high<<(half-1))|low;
        }
    }
    int mindist(long long x){
        if(x==0 || x==1)return 0;

        int len=0;
        long long t=x;
        while(t>0){
            len++;
            t>>=1;
        }

        int half=(len+1)/2;

        int shift=len-half;
        long long pre=x>>shift;
        vector<long long>cand;

        long long lopre=1ll<<(half-1);
        long long hipre=(1ll<<half)-1;

        for(int d=-1;d<=1;d++){
            long long p=pre+d;
            if(p>=lopre && p<=hipre){
                long long v=makepal(len,p);
                cand.push_back(v);
            }
        }

        if(len>1)cand.push_back((1ll<<(len-1))-1);

        cand.push_back((1ll<<len)+1);

        long long best=(1ll<<60);
        for(long long v:cand){
            if(v<0)continue;
            long long diff=v>=x?v-x:x-v;
            if(diff<best)best=diff;
        }

        return (int)best;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=mindist(nums[i]);
        }

        return ans;
    }
};