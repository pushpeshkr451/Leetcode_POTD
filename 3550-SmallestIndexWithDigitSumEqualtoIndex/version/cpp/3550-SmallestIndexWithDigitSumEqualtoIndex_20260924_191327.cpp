// Last updated: 24/09/2026, 19:13:27
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        for(int i=0;i<nums.size();i++){
5        int sum=0;
6            
7            string p=to_string(nums[i]);
8            for(int j=0;j<p.size();j++){
9                sum+=(p[j]-'0');
10            }
11            if(sum==i)return i;
12        }
13        return -1;
14    }
15};