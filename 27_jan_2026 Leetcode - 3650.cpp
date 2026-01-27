using ll=long long;
const ll INF=(1LL<<60);
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<ll>dist(n,INF);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
        dist[0]=0;
        pq.emplace(0LL,0);

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u])continue;
            if(u==n-1)break;
            for(auto &pr:adj[u]){
                int v=pr.first,w=pr.second;
                ll nd=d+w;
                if(nd<dist[v]){
                    dist[v]=nd;
                    pq.emplace(nd,v);
                }
            }
        }
        
        return dist[n-1]==INF?-1:(int)dist[n-1];
    }
};
