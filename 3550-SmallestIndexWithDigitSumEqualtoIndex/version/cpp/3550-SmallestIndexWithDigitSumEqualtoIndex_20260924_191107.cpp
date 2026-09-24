// Last updated: 24/09/2026, 19:11:07
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        const int n=min(28, int(nums.size()));
5        for(int i=0; i<n; i++){
6            int x=nums[i], digitSum=0;
7            for(; x>0; x/=10){
8                digitSum+=x%10;
9            }
10            if (digitSum==i) return i;
11        }
12        return -1;
13    }
14};