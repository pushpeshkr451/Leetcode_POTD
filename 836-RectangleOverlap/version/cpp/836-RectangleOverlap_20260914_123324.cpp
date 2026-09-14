// Last updated: 14/09/2026, 12:33:24
1class Solution {
2public:
3    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
4         return r1[0] < r2[2] && r2[0] < r1[2] &&
5               r1[1] < r2[3] && r2[1] < r1[3];
6    }
7};