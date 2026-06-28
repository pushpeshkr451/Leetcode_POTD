// Last updated: 28/06/2026, 08:13:00
1class Solution {
2public:
3    long long maxSum(vector<int>& nums, int k, int mul) {
4        sort(nums.begin(),nums.end());
5
6        auto calc = [&](long long x,long long m){
7          return max(x,x*m);  
8        };
9
10        int n=nums.size();
11
12        long long sum=0;
13        for(int i=0;i<k;i++){
14            long long m=1LL *mul-k+1+i;
15            sum+=calc(nums[n-k+i],m);
16        }
17
18        long long ans=sum;
19        for(int i=1;i<=k;i++){
20            int j=i-1;
21            long long m=1LL *mul-k+1+j;
22
23            sum-=calc(nums[n-k+j],m);
24            sum+=calc(nums[j],m);
25        }
26
27        return ans;
28    }
29};