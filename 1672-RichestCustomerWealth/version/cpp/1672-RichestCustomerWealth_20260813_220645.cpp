// Last updated: 13/08/2026, 22:06:45
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int n=nums.size();
5        int cnt=0;
6        int ans=INT_MIN;
7
8        for(auto it:nums){
9            if(it==1)cnt++;
10            else{
11                ans=max(ans,cnt);
12                cnt=0;
13            }
14        }
15        ans=max(ans,cnt);
16        return ans;
17    }
18};