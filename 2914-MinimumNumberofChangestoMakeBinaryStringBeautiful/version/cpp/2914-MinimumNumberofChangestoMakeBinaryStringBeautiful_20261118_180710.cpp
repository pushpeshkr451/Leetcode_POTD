// Last updated: 18/11/2026, 18:07:10
1class Solution {
2public:
3    int minChanges(string s) {
4        int i = 0;
5        int j = 0;
6        int cnt0 = 0;
7        int cnt1 = 0;
8
9        int ans = 0;
10
11        while(j<s.size()){
12           if(s[j]=='0') cnt0++;
13           else cnt1++;
14
15           if((j-i+1)%2==0){
16               ans += min(cnt0,cnt1);
17               cnt0 = 0;
18               cnt1 = 0;
19               i = j+1;
20           }
21           j++;
22        }
23        return ans;
24    }
25};