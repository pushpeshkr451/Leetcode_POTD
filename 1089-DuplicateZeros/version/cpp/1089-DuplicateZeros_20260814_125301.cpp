// Last updated: 14/08/2026, 12:53:01
1class Solution {
2public:
3    void duplicateZeros(vector<int>& nums) {
4        int n=nums.size();
5
6        for(int i=0;i<n;i++){
7            if(nums[i]==0){
8                nums.insert(nums.begin()+i+1,0);
9                i++;
10            }
11        }
12        while(nums.size()!=n)nums.pop_back();
13    }
14};