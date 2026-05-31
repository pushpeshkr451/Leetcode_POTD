// Last updated: 31/05/2026, 08:02:17
1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4        vector<int>freq(10,0);
5
6        while(n>0){
7            freq[n%10]++;
8            n/=10;
9        }
10
11        int ans=0;
12
13        for(int i=0;i<=9;i++){
14            ans+=i*freq[i];
15        }
16
17        return ans;
18    }
19};