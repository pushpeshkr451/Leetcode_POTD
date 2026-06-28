// Last updated: 28/06/2026, 08:23:58
1class Solution {
2public:
3    const long long INF = 1e18;
4
5    long long solve(vector<int>&nums,int k,bool mul){
6        long long dp0=-INF;
7        long long dp1=-INF;
8        long long dp2=-INF;
9
10        long long ans=-INF;
11
12        for(int x:nums){
13            long long nor=x;
14            long long chan=mul?1LL*x*k:x/k;
15
16            long long ndp0=max(dp0+nor,nor);
17            long long ndp1=max({dp0+chan,dp1+chan,chan});
18            long long ndp2=max(dp1+nor,dp2+nor);
19
20            dp0=ndp0;
21            dp1=ndp1;
22            dp2=ndp2;
23
24            ans=max({ans,dp1,dp2});
25        }
26
27        return ans;
28    }
29    long long maxSubarraySum(vector<int>& nums, int k) {
30        int n = nums.size();
31
32        long long best = -INF;
33
34        if (n > 1) {
35            long long cur = 0, mx = -INF;
36            for (int i = 0; i < n - 1; i++) {
37                cur = max(1LL * nums[i], cur + nums[i]);
38                mx = max(mx, cur);
39            }
40
41            best = max(best, mx);
42            cur = 0;
43            mx = -INF;
44
45            for (int i = 1; i < n; i++) {
46                cur = max(1LL * nums[i], cur + nums[i]);
47                mx = max(mx, cur);
48            }
49            best = max(best, mx);
50        }
51
52        best = max(best, solve(nums, k, true));
53        best = max(best, solve(nums, k, false));
54
55        return best;
56    }
57};