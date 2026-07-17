// Last updated: 17/07/2026, 21:38:14
1class Solution {
2public:
3    bool canMakeArithmeticProgression(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5
6        int n=arr.size();
7        int diff=arr[1]-arr[0];
8
9        for(int i=2;i<n;i++){
10            if(arr[i]-arr[i-1]!=diff)return false;
11        }
12
13        return true;
14    }
15};