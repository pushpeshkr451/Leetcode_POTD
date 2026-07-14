// Last updated: 15/07/2026, 03:18:05
1class Solution {
2public:
3    int sumOfMultiples(int n) {
4        int ans=0;
5
6        for(int i=1;i<=n;i++){
7            if(i%3==0||i%5==0||i%7==0)ans+=i;
8        }
9
10        return ans;
11    }
12};