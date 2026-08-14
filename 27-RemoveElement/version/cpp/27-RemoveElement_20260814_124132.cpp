// Last updated: 14/08/2026, 12:41:32
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int i = 0;
5
6        for (int j = 0; j < nums.size(); j++) {
7            if (nums[j] != 0) {
8                swap(nums[i], nums[j]);
9                i++;
10            }
11        }
12    }
13};