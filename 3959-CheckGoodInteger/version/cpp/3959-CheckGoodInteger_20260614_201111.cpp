// Last updated: 14/06/2026, 20:11:11
1class Solution {
2public:
3    bool checkGoodInteger(int n) {
4        int dsum=0,sum=0;
5
6        while(n>0){
7            int a=n%10;
8            n/=10;
9            dsum+=a;
10            sum+=(a*a);
11        }
12        return sum-dsum>=50;
13    }
14};