// Last updated: 31/05/2026, 08:15:32
1class Solution {
2public:
3    int maximumSaleItems(vector<vector<int>>& items, int budget) {
4        int n=items.size();
5
6        long long mn=2e18;
7        vector<int>freq(n+1,0);
8
9        for(auto &it:items){
10            freq[it[0]]++;
11            mn=min(mn,(long long)it[1]);
12        }
13
14        vector<int>dp(n+1,0);
15        for(int i=1;i<=n;i++){
16            if(freq[i]==0)continue;
17
18            int cnt=0;
19            for(int j=i;j<=n;j+=i){
20                cnt+=freq[j];
21            }
22            dp[i]=cnt-1;
23        }
24
25        vector<pair<long long,long long>>v;
26
27        for(auto &it:items){
28            long long fir=it[0];
29            long long sec=it[1];
30
31            if(dp[fir]>0 && sec<2*mn){
32                v.push_back({sec,dp[fir]});
33            }
34        }
35
36        sort(v.begin(),v.end());
37
38        long long b=budget;
39        long long ans=0;
40
41        for(auto &it:v){
42            long long fir=it.first;
43            long long cnt=it.second;
44
45            if(b<fir)break;
46
47            long long take=min(cnt,b/fir);
48            ans+=2*take;
49            b-=take*fir;
50        }
51
52        ans+=b/mn;
53
54        return ans;
55        
56    }
57};