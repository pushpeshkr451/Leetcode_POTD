// Last updated: 20/07/2026, 14:53:33
1class Solution {
2public:
3    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4        set<int>st(nums1.begin(),nums1.end());
5        set<int>st2;
6
7        for(auto it:nums2){
8            if(st.find(it)!=st.end())st2.insert(it);
9        }
10
11        vector<int>ans(st2.begin(),st2.end());
12        return ans;
13    }
14};