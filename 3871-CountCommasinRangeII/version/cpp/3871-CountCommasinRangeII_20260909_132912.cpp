// Last updated: 09/09/2026, 13:29:12
1class Solution {
2public:
3    long long countCommas(long long n) {
4        if(n<1000)return 0;
5
6        long long ans=0;
7
8        for(int d=4;d<=16;d++){
9            long long l=pow(10,d-1);
10
11            if(l>n)break;
12            long long r=min(n,(long long)pow(10,d)-1);
13
14            long long cnt=r-l+1;
15
16            long long com=(d-1)/3;
17            ans+=cnt*com;
18        }
19        return ans;
20    }
21};