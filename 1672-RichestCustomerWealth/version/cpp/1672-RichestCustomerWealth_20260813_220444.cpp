// Last updated: 13/08/2026, 22:04:44
1class Solution {
2public:
3    int findNumbers(vector<int>& nums) {
4        int ans=0;
5        int n=nums.size();
6        for(int i=0;i<n;i++){
7            string p=to_string(nums[i]);
8            if(p.size()%2==0)ans++;
9        }
10        return ans;
11    }
12};