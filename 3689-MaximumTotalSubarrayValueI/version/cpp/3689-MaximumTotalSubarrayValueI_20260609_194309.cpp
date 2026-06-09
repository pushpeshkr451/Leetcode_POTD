// Last updated: 09/06/2026, 19:43:09
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long ans=0;
5        int n=nums.size();
6        int mi=*min_element(nums.begin(),nums.end());
7        int ma=*max_element(nums.begin(),nums.end());
8
9        ans=(long long)k*(ma-mi);
10        return ans;
11    }
12};