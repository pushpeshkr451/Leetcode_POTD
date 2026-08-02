// Last updated: 02/08/2026, 21:51:44
1class Solution {
2public:
3    long long maxPairStrength(vector<int>& nums) {
4        long long ans=INT_MIN;
5        int n=nums.size();
6
7
8        for(int i=0;i<n;i++){
9            for(int j=i+1;j<n;j++){
10                int num=__gcd(nums[i],nums[j]);
11                long long int val=(1LL*nums[i]*nums[j])/(1LL*num*num);
12                ans=max(ans,val);
13            }
14        }
15
16        return ans;
17    }
18};