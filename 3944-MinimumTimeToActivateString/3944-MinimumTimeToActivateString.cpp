// Last updated: 09/06/2026, 19:45:09
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n=s.size();

        long long total=(long long)n*(n+1)/2;

        int l=0,r=n-1,ans=-1;
        vector<bool>star(n);

        while(l<=r){
            int m=l+(r-l)/2;

            fill(star.begin(),star.end(),false);
            for(int i=0;i<=m;i++){
                star[order[i]]=true;
            }
            long long free=0,sum=0;
            for(int i=0;i<n;i++){
                if(!star[i])free++;
                else{
                    sum+=free*(free+1LL)/2;
                    free=0;
                }
            }
            if(free)sum+=free*(free+1LL)/2;
            long long valid=total-sum;
            if(valid>=k){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};