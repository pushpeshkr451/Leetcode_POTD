// Last updated: 09/06/2026, 19:42:41
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<int, int>> pq;

        for (auto& v : sources) {
            int r = v[0], c = v[1], col = v[2];
            pq.push({r, c});
            ans[r][c] = col;
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            int sz = pq.size();

            unordered_map<int, int> mp;
            while (sz--) {
                auto [r, c] = pq.front();
                pq.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;
                    if(ans[nr][nc]!=0)continue;
                    
                    int key=nr*m+nc;
                    mp[key]=max(mp[key],ans[r][c]);
                }
            }
            for(auto &it:mp){
                int key=it.first;
                int col=it.second;

                int r=key/m;
                int c=key%m;
                
                ans[r][c]=col;
                pq.push({r,c});
            }
        }

        return ans;
    }
};