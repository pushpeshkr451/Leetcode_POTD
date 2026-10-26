// Last updated: 26/10/2026, 10:58:57
1class Solution {
2public:
3void dfs(vector<vector<int>>& grid,int i,int j,long long &sum){
4    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return;
5
6    sum+=grid[i][j];
7    grid[i][j]=0;
8
9    dfs(grid,i+1,j,sum);
10    dfs(grid,i-1,j,sum);
11    dfs(grid,i,j-1,sum);
12    dfs(grid,i,j+1,sum);
13}
14    int countIslands(vector<vector<int>>& grid, int k) {
15        int m=grid.size();
16        int n=grid[0].size();
17        int ans=0;
18
19        for(int i=0;i<m;i++){
20            for(int j=0;j<n;j++){
21                long long sum=0;
22                if(grid[i][j]!=0){
23                    dfs(grid,i,j,sum);
24                    if(sum%k==0)ans++;
25                }
26            }
27        }
28        return ans;
29    }
30};