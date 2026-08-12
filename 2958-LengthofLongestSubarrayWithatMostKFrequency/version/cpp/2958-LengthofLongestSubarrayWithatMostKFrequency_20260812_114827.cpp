// Last updated: 12/08/2026, 11:48:27
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int ans=INT_MIN;
5
6        int n=nums.size();
7        int i=0,j=0;
8
9        unordered_map<int,int>mp;
10
11        while(j<n){
12            mp[nums[j]]++;
13            if(mp[nums[j]]>k){
14                while(mp[nums[j]]>k){
15                    mp[nums[i]]--;
16                    i++;
17                }
18            }
19            else{
20                ans=max(ans,j-i+1);
21            }
22            j++;
23        }
24
25        return ans;
26    }
27};