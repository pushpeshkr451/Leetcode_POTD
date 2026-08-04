// Last updated: 04/08/2026, 14:40:34
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int n=numbers.size();
5
6        unordered_map<int,int>mp;
7
8        for(int i=0;i<n;i++){
9            mp[numbers[i]]=i+1;
10        }
11
12        for(int i=0;i<n;i++){
13            int req=target-numbers[i];
14            if(mp.find(req)!=mp.end())return {i+1,mp[req]};
15        }
16        return {};
17    }
18};