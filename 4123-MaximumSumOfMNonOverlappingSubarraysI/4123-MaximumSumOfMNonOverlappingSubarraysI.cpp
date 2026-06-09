// Last updated: 09/06/2026, 19:43:57
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();

        vector<long long>pref(n+1,0);

        for(int i=0;i<n;i++)pref[i+1]=pref[i]+nums[i];

        long long inf=1e16;
        long long ans=-inf;

        vector<long long>prev(n+1,0);

        for(int j=1;j<=m;j++){
            if(j*l>n)break;

            vector<long long>cur(n+1,-inf);
            deque<int>dq;

            for(int i=1;i<=n;i++){
                cur[i]=cur[i-1];
                int p=i-l;

                if(p>=0 && prev[p]>-inf){
                    long long val=prev[p]-pref[p];

                    while(!dq.empty()&&(prev[dq.back()]-pref[dq.back()])<=val){
                        dq.pop_back();
                    }
                    dq.push_back(p);
                }

                while(!dq.empty() && dq.front()<i-r)dq.pop_front();

                if(!dq.empty()){
                    int best=dq.front();
                    long long val=pref[i]+prev[best]-pref[best];
                    cur[i]=max(cur[i],val);
                }
            }

            ans=max(ans,cur[n]);
            prev=cur;
        }
        return ans;
    }
};