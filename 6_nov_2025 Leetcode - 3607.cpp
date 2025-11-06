class Solution {
    vector<int> p, rk;
    vector<bool> on;
    vector<set<int>> comp;

    int f(int x) {
        return p[x] == x ? x : p[x] = f(p[x]);
    }

    void u(int a, int b) {
        a = f(a); b = f(b);
        if (a == b) return;
        if (rk[a] < rk[b]) p[a] = b;
        else if (rk[b] < rk[a]) p[b] = a;
        else { p[b] = a; rk[a]++; }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& qry) {

        int n=qry.size();
        
        p.resize(c+1);
        rk.assign(c+1,0);
        for(int i=1;i<=c;i++)p[i]=i;
        for(auto &e:con)u(e[0],e[1]);
        
        on.assign(c+1,true);
        comp.resize(c+1);
                    
        for(int i=1;i<=c;i++)comp[f(i)].insert(i);
        
        vector<int>ans;
        ans.reserve(n);

        for(auto &q:qry){
            int t=q[0],x=q[1];
            if(t==1){
                if(on[x])ans.push_back(x);
                else{
                    auto &s=comp[f(x)];
                    ans.push_back(s.empty()?-1:*s.begin());
                }
            }
            else if(on[x]){
                on[x]=false;
                comp[f(x)].erase(x);
            }
            
        }
        return ans;
    }
};
