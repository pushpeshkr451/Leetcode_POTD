// Last updated: 21/06/2026, 08:13:09
1class Solution {
2public:
3    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
4        vector<vector<pair<int,int>>>adj(n);
5
6        for(auto &it:edges)adj[it[0]].push_back({it[1],it[2]});
7
8        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
9
10        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
11
12        dist[0][1]=0;
13        pq.push({0,0,1});
14
15        while(!pq.empty()){
16            auto [d,u,c]=pq.top();
17            pq.pop();
18
19            if(d>dist[u][c])continue;
20
21            if(u==n-1)return d;
22            for(auto &[v,w]:adj[u]){
23                int cnt;
24                if(labels[u]==labels[v])cnt=c+1;
25                else cnt=1;
26
27                if(cnt<=k){
28                    if(d+w<dist[v][cnt]){
29                        dist[v][cnt]=d+w;
30                        pq.push({dist[v][cnt],v,cnt});
31                    }
32                }
33            }
34        }
35        return -1;
36    }
37};