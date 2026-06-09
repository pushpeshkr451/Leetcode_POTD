// Last updated: 09/06/2026, 19:45:21
class DSU{
    vector<int>p,r;
    int comps;
    public:
    DSU(int n):p(n),r(n,0),comps(n){
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return;
        --comps;
        if(r[a]<r[b])swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]++;
        
    }
    int count() const{
        return comps;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int lo=0,hi=0;
        for(auto &e:edges)hi=max(hi,e[2]);

        auto com=[&](int t){
            DSU d(n);
            for(auto &e:edges)
                if(e[2]>t)d.unite(e[0],e[1]);
            return d.count();
        
        };
        if(com(0)>=k)return 0;
        int ans=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(com(mid)>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};