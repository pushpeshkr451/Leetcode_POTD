// Last updated: 18/08/2026, 22:54:52
1class Solution {
2public:
3    bool checkSubarraySum(vector<int>& nums, int k) {
4        unordered_map<int,int>mp;
5        mp[0]=-1;
6        
7        int sum=0;
8
9        for(int i=0;i<nums.size();i++){
10            sum+=nums[i];
11            int rem=sum%k;
12            if(mp.find(rem)!=mp.end()){
13                if(i-mp[rem]>=2)return true;
14            }
15            else{
16                mp[rem]=i;
17            }
18        }
19
20        return false;
21    }
22};