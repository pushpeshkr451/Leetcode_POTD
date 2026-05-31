// Last updated: 31/05/2026, 08:34:13
1class Solution {
2public:
3    int maximumSaleItems(vector<vector<int>>& items, int budget) {
4        int n=items.size();
5        const int m=1500;
6
7        vector<int>cnt(m+1,0);
8        for(auto &x:items)cnt[x[0]]++;
9
10        vector<int>mult(m+1,0);
11        for(int i=1;i<=m;i++){
12            for(int j=i;j<=m;j+=i){
13                mult[i]+=cnt[j];
14            }
15        }
16
17        vector<int>bonus(n);
18        for(int i=0;i<n;i++){
19            int f=items[i][0];
20            bonus[i]=mult[f]-1;
21        }
22
23        vector<int>dp(budget+1,0);
24
25        for(int i=0;i<n;i++){
26            int p=items[i][1];
27            int g=bonus[i];
28
29            vector<int>ndp=dp;
30
31            for(int r=0;r<p;r++){
32                int best=-(int)1e9;
33                for(int b=r,q=0;b<=budget;b+=p,q++){
34                    if(best!=-(int)1e9){
35                        ndp[b]=max(ndp[b],g+q+best);
36                    }
37                    best=max(best,dp[b]-q);
38                }
39            }
40
41            dp.swap(ndp);
42        }
43
44        return *max_element(dp.begin(),dp.end());
45    }
46};