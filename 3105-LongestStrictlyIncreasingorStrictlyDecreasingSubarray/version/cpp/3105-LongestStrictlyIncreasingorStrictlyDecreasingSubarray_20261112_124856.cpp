// Last updated: 12/11/2026, 12:48:56
1class Solution {
2public:
3    int longestMonotonicSubarray(vector<int>& nums) {
4        int a=1,b=1;
5        int maxa=1,maxb=1;
6        int n=nums.size();
7        for(int i=0;i<n-1;i++){
8            if(nums[i]<nums[i+1]){
9                a++;
10                b=1;
11                maxa=max(a,maxa);
12            }
13            else if(nums[i]>nums[i+1]){
14                b++;
15                a=1;
16                maxb=max(maxb,b);
17            }
18            else if(nums[i]==nums[i+1]){
19                a=1;
20                b=1;
21            }
22        }
23        return max(maxa,maxb);
24    }
25};