// Last updated: 12/08/2026, 11:47:25
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int n=nums.size();
5        int i=0,j=0;
6        unordered_map<int,int>mp;
7        int ans=INT_MIN;
8        while(j<n){
9            mp[nums[j]]++;
10            while(mp[nums[j]]>k){
11                mp[nums[i]]--;
12                i++;
13            }
14            ans=max(ans,j-i+1);
15            j++;
16        }
17        return ans;
18    }
19};