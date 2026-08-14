// Last updated: 14/08/2026, 13:16:47
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int cnt0=0,cnt1=0,cnt2=0;
5
6        for(auto it:nums){
7            if(it==0)cnt0++;
8            else if(it==1)cnt1++;
9            else cnt2++;
10        }
11        
12        int j=0;
13        for(int i=0;i<cnt0;i++)nums[j++]=0;
14
15        for(int i=0;i<cnt1;i++)nums[j++]=1;
16
17        for(int i=0;i<cnt2;i++)nums[j++]=2;
18    }
19};