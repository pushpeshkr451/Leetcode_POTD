// Last updated: 20/06/2026, 20:06:26
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        vector<string>grid(m,string(n,'#'));
5
6        for(int j=0;j<n;j++)grid[0][j]='.';
7        for(int i=0;i<m;i++)grid[i][n-1]='.';
8
9        return grid;
10    }
11};