// Last updated: 12/08/2026, 22:28:10
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>ans(n);
6
7        for(int i=0;i<n;i++){
8            int cnt=0;
9            for(int j=0;j<n;j++){
10                if(nums[i]>nums[j])cnt++;
11            }
12
13            ans[i]=cnt;
14        }
15        return ans;
16    }
17};