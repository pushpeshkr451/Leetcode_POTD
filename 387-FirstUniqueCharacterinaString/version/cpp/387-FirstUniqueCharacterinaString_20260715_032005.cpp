// Last updated: 15/07/2026, 03:20:05
1class Solution {
2public:
3    int xorOperation(int n, int start) {
4        int ans=0;
5
6        for(int i=0;i<n;i++){
7            int num=start+2*i;
8            ans^=num;
9        }
10
11        return ans;
12        
13    }
14};