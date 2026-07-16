// Last updated: 16/07/2026, 21:59:54
1class Solution {
2public:
3    int deleteGreatestValue(vector<vector<int>>& grid) {
4        int ans=0;
5        for(int i=0;i<grid.size();i++){
6            sort(grid[i].begin(),grid[i].end());
7        }
8
9        for(int j=0;j<grid[0].size();j++){
10            int n=0;
11            for(int i=0;i<grid.size();i++)n=max(n,grid[i][j]);
12            ans+=n;
13        }
14
15        return ans;
16        
17    }
18};