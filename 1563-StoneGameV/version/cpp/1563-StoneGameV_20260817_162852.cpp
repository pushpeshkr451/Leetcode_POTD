// Last updated: 17/08/2026, 16:28:52
1class Solution {
2private:
3    vector<vector<int>> f;
4
5public:
6    int dfs(const vector<int>& stoneValue, int left, int right) {
7        if (left == right) {
8            return 0;
9        }
10        if (f[left][right]) {
11            return f[left][right];
12        }
13
14        int sum = accumulate(stoneValue.begin() + left,
15                             stoneValue.begin() + right + 1, 0);
16        int suml = 0;
17        for (int i = left; i < right; ++i) {
18            suml += stoneValue[i];
19            int sumr = sum - suml;
20            if (suml < sumr) {
21                f[left][right] =
22                    max(f[left][right], dfs(stoneValue, left, i) + suml);
23            } else if (suml > sumr) {
24                f[left][right] =
25                    max(f[left][right], dfs(stoneValue, i + 1, right) + sumr);
26            } else {
27                f[left][right] =
28                    max(f[left][right], max(dfs(stoneValue, left, i),
29                                            dfs(stoneValue, i + 1, right)) +
30                                            suml);
31            }
32        }
33        return f[left][right];
34    }
35
36    int stoneGameV(vector<int>& stoneValue) {
37        int n = stoneValue.size();
38        f.assign(n, vector<int>(n));
39        return dfs(stoneValue, 0, n - 1);
40    }
41};