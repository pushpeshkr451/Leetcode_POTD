// Last updated: 14/08/2026, 13:18:20
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
12        for(int i=0;i<nums.size();i++){
13            if(cnt0>0){
14                nums[i]=0;
15                cnt0--;
16            }
17            else if(cnt1>0){
18                nums[i]=1;
19                cnt1--;
20            }
21            else nums[i]=2;
22        }
23    }
24};