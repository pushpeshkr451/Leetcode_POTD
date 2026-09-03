// Last updated: 03/09/2026, 21:50:42
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int n=nums1.size();
5
6        bool flag=true;
7
8        int mn=INT_MAX;
9
10        for(int i=0;i<n;i++){
11            if(nums1[i]%2)flag=false;
12            mn=min(mn,nums1[i]);
13        }
14
15        if(flag)return true;
16        if(mn%2)return true;
17
18        return false;
19    }
20};