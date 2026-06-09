// Last updated: 09/06/2026, 19:44:06
class Solution {
public:

    bool check(int mid,int n,vector<vector<int>>&edges,int source,int target,int k){

        vector<vector<pair<int,int>>>adj(n);

        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];

            int cost=(w>mid);
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        deque<int>dq;
        vector<int>dist(n,1e9);

        dist[source]=0;
        dq.push_front(source);

        while(!dq.empty()){
            int u=dq.front();
            dq.pop_front();

            for(auto &[v,c]:adj[u]){
                if(dist[u]+c<dist[v]){
                    dist[v]=dist[u]+c;

                    if(c==0)dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
        return dist[target]<=k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source==target)return 0;

        int mx=0;
        for(auto &e:edges){
            mx=max(mx,e[2]);
        }

        int l=0,r=mx,ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid,n,edges,source,target,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};