// Last updated: 10/11/2026, 13:19:43
1class Solution {
2public:
3    int climbStairs(int n, vector<int>& costs) {
4        int first = 0;
5        int second = 0;
6        int third = 0;
7        int current;
8        for (int i = 0; i < costs.size(); i++) {
9            current = min(first + 9, min(second + 4, third + 1)) + costs[i];
10            first = second;
11            second = third;
12            third = current;
13        }
14        return current;
15    }
16};