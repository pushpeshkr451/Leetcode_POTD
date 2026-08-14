// Last updated: 14/08/2026, 12:31:08
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        set<int>st(nums.begin(),nums.end());
5        int i=0;
6        for(auto it:st)nums[i++]=it;
7        return st.size();
8    }
9};