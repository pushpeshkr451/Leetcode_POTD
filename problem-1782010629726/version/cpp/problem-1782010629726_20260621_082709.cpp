// Last updated: 21/06/2026, 08:27:09
1class Solution {
2public:
3    long long mod=1e9+7;
4
5    long long check(long long mid,vector<int>&value,vector<int>&decay){
6        long long cnt=0;
7        for(int i=0;i<value.size();i++){
8            if(value[i]>=mid)cnt+=(value[i]-mid)/decay[i]+1;
9        }
10        return cnt;
11    }
12    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
13        long long low=1,high=1000000005;
14
15        long long x=high;
16        while(low<=high){
17            long long mid=low+(high-low)/2;
18
19            if(check(mid,value,decay)<=m){
20                x=mid;
21                high=mid-1;
22            }
23            else{
24                low=mid+1;
25            }
26        }
27
28        long long ans=0;
29        long long taken=0;
30
31        for(int i=0;i<value.size();i++){
32            if(value[i]>=x){
33                long long cnt=(value[i]-x)/decay[i]+1;
34                taken+=cnt;
35                long long v=value[i]%mod;
36                long long c=cnt%mod;
37                long long d=decay[i]%mod;
38
39                long long term1=(c*v)%mod;
40
41                long long chose=(c*((cnt-1)%mod))%mod;
42                chose=(chose*500000004LL)%mod;
43
44                long long term2=(d*chose)%mod;
45                long long cur=(term1-term2+mod)%mod;
46                ans=(ans+cur)%mod;
47            }
48        }
49        long long rem=m-taken;
50        if(rem>0 && x>1)ans=(ans+((rem%mod)*((x-1)%mod))%mod)%mod;
51
52        return ans;
53    }
54};