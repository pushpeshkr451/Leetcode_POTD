// Last updated: 13/09/2026, 15:56:57
1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5        vector<pair<int,int>> A, B;
6        for (int i = 0; i < n; ++i) {
7            for (int j = 0; j < n; ++j) {
8                if (img1[i][j] == 1) A.emplace_back(i, j);
9                if (img2[i][j] == 1) B.emplace_back(i, j);
10            }
11        }
12        vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));
13        int best = 0;
14        for (auto& a : A) {
15            for (auto& b : B) {
16                int dx = b.first - a.first + n;
17                int dy = b.second - a.second + n;
18                best = max(best, ++cnt[dx][dy]);
19            }
20        }
21        return best;
22    }
23};