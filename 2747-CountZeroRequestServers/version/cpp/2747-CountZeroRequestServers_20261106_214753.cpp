// Last updated: 06/11/2026, 21:47:53
1class Solution {
2public:
3    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
4                             vector<int>& queries) {
5        int s = queries.size();
6        vector<int> arr(s);
7        sort(logs.begin(), logs.end(),
8             [](auto& a, auto& b) { return a[1] < b[1]; });
9        int m = logs.size();
10        vector<pair<int, int>> sq;
11        for (int i = 0; i < s; i++) {
12            sq.push_back({queries[i], i});
13        }
14        sort(sq.begin(), sq.end());
15        int l = 0;
16        int r = 0;
17        int active = 0;
18        vector<int> freq(n + 1, 0);
19        for (auto [en, idx] : sq) {
20            int st = en - x;
21            while (r < m && logs[r][1] <= en) {
22                int id = logs[r][0];
23                if (freq[id] == 0) {
24                    active++;
25                }
26                freq[id]++;
27                r++;
28            }
29            while (l < r && logs[l][1] < st) {
30                int id = logs[l][0];
31                freq[id]--;
32                if (freq[id] == 0) {
33                    active--;
34                }
35                l++;
36            }
37            arr[idx] = n - active;
38        }
39        return arr;
40    }
41};