// Last updated: 14/08/2026, 12:32:05
1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        int index = 0;
5        for(int i = 0; i< nums.size(); i++){
6            if(nums[i] != val){
7                nums[index] = nums[i];
8                index++;
9            }
10        }
11        return index;
12    }
13};