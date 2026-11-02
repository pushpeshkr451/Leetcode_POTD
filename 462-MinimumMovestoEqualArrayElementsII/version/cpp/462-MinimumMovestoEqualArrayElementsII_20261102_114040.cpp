// Last updated: 02/11/2026, 11:40:40
1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int ans = 0;
6
7        int mid = nums.size()/2;
8
9        for(int i = 0; i < nums.size(); i++) {
10            if(nums[i] < nums[mid]) {
11                ans += nums[mid] - nums[i];
12            } else {
13                ans += nums[i] - nums[mid];
14            }
15        }
16
17        return ans;
18    }
19};