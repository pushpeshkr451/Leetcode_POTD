// Last updated: 22/08/2026, 07:49:02
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        string s=to_string(n);;
5
6        long long sum=0,prod=1;
7
8        for(auto it:s){
9            int num=it-'0';
10            sum+=num;
11            prod*=num;
12        }
13
14        return n%(prod+sum)==0?true:false;
15    }
16};