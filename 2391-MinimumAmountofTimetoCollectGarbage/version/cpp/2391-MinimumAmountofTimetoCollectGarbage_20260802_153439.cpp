// Last updated: 02/08/2026, 15:34:39
1class Solution {
2public:
3    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
4
5        int n = garbage.size();
6
7        for (int i = 1; i < travel.size(); i++) {
8            travel[i] += travel[i - 1];
9        }
10
11        int lastM = 0, lastP = 0, lastG = 0;
12        int ans = 0;
13
14        for (int i = 0; i < n; i++) {
15
16            ans += garbage[i].size();
17
18            for (char ch : garbage[i]) {
19                if (ch == 'M')
20                    lastM = i;
21                else if (ch == 'P')
22                    lastP = i;
23                else
24                    lastG = i;
25            }
26        }
27
28        if (lastM > 0)
29            ans += travel[lastM - 1];
30
31        if (lastP > 0)
32            ans += travel[lastP - 1];
33
34        if (lastG > 0)
35            ans += travel[lastG - 1];
36
37        return ans;
38    }
39};