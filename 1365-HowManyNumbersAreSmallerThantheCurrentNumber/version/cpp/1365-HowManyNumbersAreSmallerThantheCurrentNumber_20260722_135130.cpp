// Last updated: 22/07/2026, 13:51:30
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        vector<int>sor_ted(nums.begin(),nums.end());
5        sort(sor_ted.begin(),sor_ted.end());
6        
7        vector<int>ans;
8        
9        for(auto it:nums){
10            int num=lower_bound(sor_ted.begin(),sor_ted.end(),it)-sor_ted.begin();
11            ans.push_back(num);
12        }
13        return ans;
14    }
15};