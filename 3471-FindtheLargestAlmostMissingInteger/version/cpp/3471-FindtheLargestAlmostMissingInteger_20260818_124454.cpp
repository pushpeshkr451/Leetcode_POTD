// Last updated: 18/08/2026, 12:44:54
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        unordered_map<int,int>mp;
5        set<pair<int,int>>st;
6        int count=1;
7        for(int i=0;i<k;i++){
8            st.insert({count,nums[i]});
9        }
10        count++;
11        for(int i=1;i<=nums.size()-k;i++){
12            for(int j=i;j<i+k;j++){
13              st.insert({count,nums[j]});
14            }
15            count++;
16        }
17        for(auto it:st){
18            mp[it.second]++;
19        }
20        int ma=INT_MIN;
21        for(auto it:mp){
22            if(it.second==1)ma=max(ma,it.first);
23        }
24        if(ma==INT_MIN)return -1;
25        return ma;
26    }
27};