// Last updated: 12/07/2026, 13:46:42
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        set<int>st(arr.begin(),arr.end());
5        vector<int>nums(st.begin(),st.end());
6
7        sort(nums.begin(),nums.end());
8        unordered_map<int,int>mp;
9
10        for(int i=0;i<nums.size();i++)mp[nums[i]]=i+1;
11
12        for(int i=0;i<arr.size();i++)arr[i]=mp[arr[i]];
13
14        return arr;
15
16    }
17};