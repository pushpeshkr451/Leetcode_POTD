// Last updated: 13/08/2026, 22:15:47
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int lo=0,hi=n-1;
6        while(lo<=hi){
7            int mid=lo+(hi-lo)/2;
8            if(nums[mid]==target)return mid;
9            else if(nums[mid]>target)hi=mid-1;
10            else lo=mid+1;
11        }
12        return -1;
13    }
14};