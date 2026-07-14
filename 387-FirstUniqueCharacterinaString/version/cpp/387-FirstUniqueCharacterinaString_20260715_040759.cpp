// Last updated: 15/07/2026, 04:07:59
1class Solution {
2public:
3    bool canAliceWin(vector<int>& nums) {
4        int total=accumulate(nums.begin(),nums.end(),0);
5        int ans=INT_MIN;
6        int sum1=0,sum2=0;
7
8        for(auto it:nums){
9            string s=to_string(it);
10            if(s.size()==1)sum1+=it;
11            else if(s.size()==2)sum2+=it;
12        }
13
14        ans=max(sum1,sum2);
15        return ans>total-ans?1:0;
16    }
17};