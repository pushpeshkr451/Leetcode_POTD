// Last updated: 09/06/2026, 19:42:47
class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {

        int n=nums.size();

        vector<vector<int>>adj(n);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans=0;

        for(int mask=1;mask<(1<<n);mask++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    sum+=nums[i];
                }
            }

            if(sum%2!=0)continue;

            queue<int>q;
            vector<int>vis(n,0);
            int start=-1;

            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    start=i;
                    break;
                }
            }

            q.push(start);
            vis[start]=1;

            int cnt=0;

            while(!q.empty()){
                int u=q.front();
                q.pop();
                cnt++;

                for(int v:adj[u]){
                    if((mask&(1<<v)) && !vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }

            int total=__builtin_popcount(mask);

            if(cnt==total)ans++;
        }

        return ans;
    }
};