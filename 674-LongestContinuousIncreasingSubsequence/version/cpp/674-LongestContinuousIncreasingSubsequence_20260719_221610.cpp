// Last updated: 19/07/2026, 22:16:10
1class Solution {
2public:
3    int findLengthOfLCIS(vector<int>& nums) {
4        int n=nums.size();
5        int i=0,j=1;
6
7        int ans=1;
8        while(j<n){
9            if(nums[j]>nums[j-1]){
10                ans=max(ans,j-i+1);
11            }
12            else i=j;
13            j++;
14        }
15
16        return ans;
17    }
18};