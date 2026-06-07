// Last updated: 07/06/2026, 08:03:00
1class Solution {
2public:
3    int sumOfGoodIntegers(int n, int k) {
4        int ans=0;
5
6        for(int i=1;i<=n+k;i++){
7            if(abs(i-n)<=k && (n&i)==0)ans+=i;
8        }
9
10        return ans;
11    }
12};