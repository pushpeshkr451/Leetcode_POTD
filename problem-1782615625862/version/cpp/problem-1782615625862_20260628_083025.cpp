// Last updated: 28/06/2026, 08:30:25
1class Solution {
2public:
3    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
4        vector<vector<pair<int,int>>>adj(n);
5
6        for(auto &e:edges){
7            adj[e[0]].push_back({e[1],e[2]});
8        }
9
10        priority_queue<tuple<long long,int,int>,vector<tuple<long long ,int ,int>>,greater<tuple<long long,int,int>>>pq;
11
12        vector<int>mx(n,-1);
13
14        pq.push({0,-power,source});
15
16        while(!pq.empty()){
17            auto [time,negpower,u]=pq.top();
18            pq.pop();
19
20            int cur=-negpower;
21            if(u==target)return {time,cur};
22            if(cur<=mx[u])continue;
23            mx[u]=cur;
24
25            if(cur<cost[u])continue;
26
27            for(auto [v,w]:adj[u])pq.push({time+w,-(cur-cost[u]),v});
28        }
29        return {-1,-1};
30    }
31};