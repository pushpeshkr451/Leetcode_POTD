// Last updated: 08/09/2026, 06:39:27
1class Solution {
2public:
3    int countCommas(int n) {
4        int ans=0;
5
6        for(int i=1000;i<=n;i++){
7            ans++;
8        }
9
10        return ans;
11    }
12};