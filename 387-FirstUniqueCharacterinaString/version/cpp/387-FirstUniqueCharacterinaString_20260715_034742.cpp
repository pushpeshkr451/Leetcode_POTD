// Last updated: 15/07/2026, 03:47:42
1class Solution {
2public:
3    int subtractProductAndSum(int n) {
4        long long pro=1,sum=0;
5        while(n>0){
6            int num=n%10;
7            pro*=num;
8            sum+=num;
9            n/=10;
10        }
11
12        return int(pro-sum);
13    }
14};