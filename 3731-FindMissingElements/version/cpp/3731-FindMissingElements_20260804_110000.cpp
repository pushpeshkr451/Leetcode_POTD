// Last updated: 04/08/2026, 11:00:00
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        vector<int>ans;
5        int mi=*min_element(nums.begin(),nums.end());
6        int ma=*max_element(nums.begin(),nums.end());
7
8        set<int>st(nums.begin(),nums.end());
9
10        for(int i=mi+1;i<ma;i++){
11            if(st.find(i)==st.end()){
12                ans.push_back(i);
13            }
14        }
15        return ans;
16    }
17};