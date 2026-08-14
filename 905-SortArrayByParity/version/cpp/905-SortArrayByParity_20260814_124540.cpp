// Last updated: 14/08/2026, 12:45:40
1class Solution {
2public:
3    vector<int> sortArrayByParity(vector<int>& nums) {
4        vector<int>ans;
5
6        for(auto it:nums){
7            if(!(it%2))ans.push_back(it);
8        }
9        
10        for(auto it:nums){
11            if(it%2)ans.push_back(it);
12        }
13
14        return ans;
15    }
16};