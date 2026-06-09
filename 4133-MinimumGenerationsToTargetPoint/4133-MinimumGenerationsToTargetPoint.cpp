// Last updated: 09/06/2026, 19:43:50
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        bool vis[7][7][7] = {};
        vector<vector<int>> all;

        for (auto& p : points) {
            vis[p[0]][p[1]][p[2]] = 1;
            all.push_back(p);

            if (p == target)
                return 0;
        }

        int gen = 1;

        while (true) {
            vector<vector<int>> cur;
            int n = all.size();

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (all[i] == all[j])
                        continue;
                    vector<int> c(3);

                    c[0] = (all[i][0] + all[j][0]) / 2;
                    c[1] = (all[i][1] + all[j][1]) / 2;
                    c[2] = (all[i][2] + all[j][2]) / 2;

                    if (!vis[c[0]][c[1]][c[2]]) {
                        vis[c[0]][c[1]][c[2]] = 1;

                        if (c == target)
                            return gen;

                        cur.push_back(c);
                    }
                }
            }
            if(cur.empty())break;

            for(auto &p:cur){
                all.push_back(p);
            }

            gen++;
        }
        return -1;
    }
};