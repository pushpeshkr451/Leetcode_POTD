// Last updated: 19/06/2026, 18:23:16
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int n = gain.size();
5        vector<int>pre(n);
6        
7        pre[0]=gain[0];
8        for(int i = 1; i < n; i++){
9            pre[i] = pre[i-1] + gain[i];
10        }
11        int ans=*max_element(pre.begin(),pre.end());
12        return ans>=0 ? ans:0;
13    }
14};