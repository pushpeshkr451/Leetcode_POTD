// Last updated: 01/06/2026, 13:31:31
1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        sort(cost.begin(), cost.end());
5
6        int ans = 0;
7
8        for(int i = cost.size()-1; i >= 0; i -= 3) {
9            ans += cost[i];
10            if(i - 1 >= 0)
11                ans += cost[i - 1];
12        }
13
14        return ans;
15    }
16};