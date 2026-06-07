// Last updated: 07/06/2026, 08:42:12
1class Solution {
2public:
3
4    vector<pair<long long,int>>dp;
5    vector<long long>pref;
6    int n;
7
8    pair<long long ,int>check(long long num,int l,int r){
9        dp[0]={0,0};
10        deque<int>q;
11
12        for(int i=1;i<=n;i++){
13            dp[i]=dp[i-1];
14            int p=i-l;
15
16            if(p>=0){
17                long long val=dp[p].first-pref[p];
18                int cnt=dp[p].second;
19                while(!q.empty()){
20                    int b=q.back();
21                    long long val2=dp[b].first-pref[b];
22                    int cnt2=dp[b].second;
23
24                    if(val>val2 || (val==val2 && cnt>=cnt2))q.pop_back();
25                    else break;
26                }
27                q.push_back(p);
28            }
29
30            while(!q.empty() && q.front()<i-r)q.pop_front();
31
32            if(!q.empty()){
33                int best=q.front();
34
35                long long sum=pref[i]-num+dp[best].first-pref[best];
36                int cnt=dp[best].second+1;
37                if(sum>dp[i].first||(sum==dp[i].first && cnt>dp[i].second))dp[i]={sum,cnt};
38            }
39        }
40        return dp[n];
41    }
42    long long maximumSum(vector<int>& nums, int m, int l, int r) {
43        n=nums.size();
44        pref.assign(n+1,0);
45
46        for(int i=0;i<n;i++)pref[i+1]=pref[i]+nums[i];
47
48        long long maxi=-1e18;
49        deque<int>dq;
50
51        for(int i=l;i<=n;i++){
52            int p=i-l;
53
54            while(!dq.empty()&&pref[dq.back()]>=pref[p])dq.pop_back();
55
56            dq.push_back(p);
57
58            while(!dq.empty()&&dq.front()<i-r)dq.pop_front();
59
60            if(!dq.empty())maxi=max(maxi,pref[i]-pref[dq.front()]);
61        }
62
63        if(maxi<=0)return maxi;
64        dp.assign(n+1,{0,0});
65
66        auto cur=check(0,l,r);
67
68        if(cur.second<=m)return cur.first;
69
70        long long low=0;
71        long long high=1e11;
72        long long best=0;
73
74        while(low<=high){
75            long long mid=low+(high-low)/2;
76            auto res=check(mid,l,r);
77
78            if(res.second>=m){
79                best=mid;
80                low=mid+1;
81            }
82            else high=mid-1;
83        }
84
85        auto res=check(best,l,r);
86
87        return res.first+best*m;
88    }
89};