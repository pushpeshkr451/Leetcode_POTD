// Last updated: 07/06/2026, 08:18:31
1class Solution {
2public:
3    long long maximumSum(vector<int>& nums, int m, int l, int r) {
4        int n=nums.size();
5
6        vector<long long>pref(n+1,0);
7
8        for(int i=0;i<n;i++)pref[i+1]=pref[i]+nums[i];
9
10        long long inf=1e16;
11        long long ans=-inf;
12
13        vector<long long>prev(n+1,0);
14
15        for(int j=1;j<=m;j++){
16            if(j*l>n)break;
17
18            vector<long long>cur(n+1,-inf);
19            deque<int>dq;
20
21            for(int i=1;i<=n;i++){
22                cur[i]=cur[i-1];
23                int p=i-l;
24
25                if(p>=0 && prev[p]>-inf){
26                    long long val=prev[p]-pref[p];
27
28                    while(!dq.empty()&&(prev[dq.back()]-pref[dq.back()])<=val){
29                        dq.pop_back();
30                    }
31                    dq.push_back(p);
32                }
33
34                while(!dq.empty() && dq.front()<i-r)dq.pop_front();
35
36                if(!dq.empty()){
37                    int best=dq.front();
38                    long long val=pref[i]+prev[best]-pref[best];
39                    cur[i]=max(cur[i],val);
40                }
41            }
42
43            ans=max(ans,cur[n]);
44            prev=cur;
45        }
46        return ans;
47    }
48};