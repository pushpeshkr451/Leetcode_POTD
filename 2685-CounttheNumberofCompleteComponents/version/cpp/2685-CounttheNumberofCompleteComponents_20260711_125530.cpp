// Last updated: 11/07/2026, 12:55:30
1class Solution {
2public:
3    void bfs(int node,vector<vector<int>> &adj,vector<int> &comp,vector<bool> &vis){
4        queue<int> q;
5        q.push(node);
6        vis[node]=true;
7
8        while(!q.empty()){
9            int n=q.front();
10            q.pop();
11            comp.push_back(n);
12            for(auto it:adj[n]){
13                if(!vis[it]){
14                    q.push(it);
15                    vis[it]=true;
16                }
17            }
18        }
19    }
20    int countCompleteComponents(int n, vector<vector<int>>& edges) {
21        vector<vector<int>> adj(n);
22        for(auto it:edges){
23            adj[it[0]].push_back(it[1]);
24            adj[it[1]].push_back(it[0]);
25        }
26        int ans=0;
27        vector<bool> vis(n,false);
28        for(int i=0;i<n;i++){
29
30            if(!vis[i]){
31                vector<int> comp;
32                bfs(i,adj,comp,vis);
33                bool iscomp=true;
34                for(auto it: comp){
35                    if(adj[it].size()!=comp.size()-1){
36                        iscomp=false;
37                        break;
38                    }
39                }
40                if(iscomp)ans++;
41            }
42        }
43        return ans;
44    }
45};