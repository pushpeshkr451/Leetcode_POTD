// Last updated: 09/06/2026, 19:45:41
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> values;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        values.push_back(grid[r][c]);
                    }
                }

                sort(values.begin(), values.end());

                int mi = INT_MAX;

                for (int idx = 1; idx < values.size(); ++idx) {
                    if (values[idx] != values[idx - 1]) {
                        mi = min(mi, abs(values[idx] - values[idx - 1]));
                    }
                }
                ans[i][j] = (mi == INT_MAX) ? 0 : mi;
            }
        }

        return ans;
    }
};
