// Last updated: 21/07/2026, 22:14:55
1class Solution {
2public:
3    int alternatingSum(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0;
6
7        for(int i=0;i<n;i++){
8            if(i%2)ans-=nums[i];
9            else ans+=nums[i];
10        }
11
12        return ans;
13    }
14};