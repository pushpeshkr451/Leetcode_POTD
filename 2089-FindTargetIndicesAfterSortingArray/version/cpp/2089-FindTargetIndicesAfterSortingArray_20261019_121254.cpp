// Last updated: 19/10/2026, 12:12:54
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int cntLess = 0, cntGr = 0;
5        for(auto it : nums){
6            if(it < target){
7                cntLess++;
8            }else if(it > target){
9                cntGr++;
10            }
11        }
12        vector<int> sol;
13        int n = nums.size() - cntGr - cntLess;
14        for(int i = 0; i < n; i++){
15            sol.push_back(i + cntLess);
16        }
17        return sol;
18    }
19};