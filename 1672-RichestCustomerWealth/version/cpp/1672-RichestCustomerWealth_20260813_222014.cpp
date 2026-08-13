// Last updated: 13/08/2026, 22:20:14
1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int n=nums.size();
5
6        int lo=0,hi=n-1;
7
8        while(lo<=hi){
9            int mid=lo+(hi-lo)/2;
10
11            if(nums[mid]==target)return mid;
12            else if(nums[mid]<target)lo=mid+1;
13            else hi=mid-1;
14        }
15        return lo;
16    }
17};