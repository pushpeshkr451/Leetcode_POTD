// Last updated: 20/06/2026, 20:17:13
1class Solution {
2public:
3
4    vector<vector<int>>adj;
5    vector<int>base;
6
7    long long dfs(int node){
8        if(adj[node].empty())return base[node];
9
10        long long mn=LLONG_MAX;
11        long long mx=-1;
12
13        for(auto child:adj[node]){
14            long long cur=dfs(child);
15            mn=min(mn,cur);
16            mx=max(mx,cur);
17        }
18
19        return mx+(mx-mn)+base[node];
20    }
21    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
22        base=baseTime;
23        adj.assign(n,{});
24
25        for(auto &it:edges){
26            adj[it[0]].push_back(it[1]);
27        }
28        return dfs(0);
29        
30    }
31};