// Last updated: 13/08/2026, 22:09:12
1class Solution {
2public:
3    int thirdMax(vector<int>& nums) {
4        set<int>st(nums.begin(),nums.end());
5
6        vector<int>uniq(st.begin(),st.end());
7
8        sort(uniq.begin(),uniq.end());
9        int n=uniq.size();
10        if(uniq.size()<3)return uniq[n-1];
11        return uniq[n-3];
12    }
13};