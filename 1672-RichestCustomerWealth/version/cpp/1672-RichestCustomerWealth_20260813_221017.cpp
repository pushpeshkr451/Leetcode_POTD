// Last updated: 13/08/2026, 22:10:17
1class Solution {
2public:
3    int thirdMax(vector<int>& nums) {
4        set<int> st(nums.begin(), nums.end());
5        if (st.size() < 3) return *st.rbegin();
6        return *next(st.rbegin(), 2);
7    }
8};