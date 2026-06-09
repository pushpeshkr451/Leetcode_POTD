// Last updated: 09/06/2026, 19:43:55
class Solution {
public:

    vector<pair<long long,int>>dp;
    vector<long long>pref;
    int n;

    pair<long long ,int>check(long long num,int l,int r){
        dp[0]={0,0};
        deque<int>q;

        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            int p=i-l;

            if(p>=0){
                long long val=dp[p].first-pref[p];
                int cnt=dp[p].second;
                while(!q.empty()){
                    int b=q.back();
                    long long val2=dp[b].first-pref[b];
                    int cnt2=dp[b].second;

                    if(val>val2 || (val==val2 && cnt>=cnt2))q.pop_back();
                    else break;
                }
                q.push_back(p);
            }

            while(!q.empty() && q.front()<i-r)q.pop_front();

            if(!q.empty()){
                int best=q.front();

                long long sum=pref[i]-num+dp[best].first-pref[best];
                int cnt=dp[best].second+1;
                if(sum>dp[i].first||(sum==dp[i].first && cnt>dp[i].second))dp[i]={sum,cnt};
            }
        }
        return dp[n];
    }
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        n=nums.size();
        pref.assign(n+1,0);

        for(int i=0;i<n;i++)pref[i+1]=pref[i]+nums[i];

        long long maxi=-1e18;
        deque<int>dq;

        for(int i=l;i<=n;i++){
            int p=i-l;

            while(!dq.empty()&&pref[dq.back()]>=pref[p])dq.pop_back();

            dq.push_back(p);

            while(!dq.empty()&&dq.front()<i-r)dq.pop_front();

            if(!dq.empty())maxi=max(maxi,pref[i]-pref[dq.front()]);
        }

        if(maxi<=0)return maxi;
        dp.assign(n+1,{0,0});

        auto cur=check(0,l,r);

        if(cur.second<=m)return cur.first;

        long long low=0;
        long long high=1e11;
        long long best=0;

        while(low<=high){
            long long mid=low+(high-low)/2;
            auto res=check(mid,l,r);

            if(res.second>=m){
                best=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        auto res=check(best,l,r);

        return res.first+best*m;
    }
};