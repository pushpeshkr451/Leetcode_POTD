// Last updated: 09/06/2026, 19:44:03
class Solution {
public:
    vector<int>parent,parity;
    int find(int x){
        if(parent[x]!=x){
            int p=parent[x];
            parent[x]=find(parent[x]);
            parity[x]^=parity[p];
        }

        return parent[x];
    }

    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        parity.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int cnt=0;

        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];

            int pu=find(u);
            int pv=find(v);

            if(pu!=pv){
                parent[pu]=pv;
                parity[pu]=parity[u]^parity[v]^w;
                cnt++;
            }
            else{
                if((parity[u]^parity[v])==w){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};