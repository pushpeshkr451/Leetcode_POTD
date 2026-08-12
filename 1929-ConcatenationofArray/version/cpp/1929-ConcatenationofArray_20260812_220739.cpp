// Last updated: 12/08/2026, 22:07:39
1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4        int n = nums.size();
5        int sum = 0;
6        vector<int>result(n);
7        result[0]=nums[0];
8        for(int i=1;i<n;i++){
9            result[i]=result[i-1]+nums[i];
10        }
11        return result;
12    }
13};