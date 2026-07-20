// Last updated: 20/07/2026, 21:42:23
1class Solution {
2public:
3    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
4        set<int> s1,s2;
5        vector<vector<int>> ans(2);
6        for(auto i : nums1){
7            s1.insert(i);
8        }
9        for(auto i : nums2){
10            s2.insert(i);
11        }
12        for(auto i : s1){
13            if(s2.find(i) == s2.end()){
14                ans[0].push_back(i);
15            }
16        }
17        for(auto i : s2){
18            if(s1.find(i) == s1.end()){
19                ans[1].push_back(i);
20            }
21        }
22        return ans;
23    }
24};