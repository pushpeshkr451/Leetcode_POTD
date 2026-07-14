// Last updated: 15/07/2026, 03:55:52
1class Solution {
2public:
3    int arraySign(vector<int>& nums) {
4        int cnt0=0;
5        for(auto it:nums){
6            if(it==0)return 0;
7            else if(it<0)cnt0++;
8            
9        }
10
11        if(cnt0%2==0)return 1;
12        return -1;
13    }
14};