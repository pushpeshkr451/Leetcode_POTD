// Last updated: 09/11/2026, 12:58:52
1class Solution {
2public:
3    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& lo) {
4        set<int> free;
5        int n = arr.size();
6        for (int i = 0; i < 2 * k - 1; i++)
7            free.insert(i);
8        vector<int> cnt(k, 0);
9        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
10        for (int i = 0; i < n; i++) {
11            int at = arr[i];
12            int load = lo[i];
13            while (!pq.empty() and pq.top().first <= at) {
14                auto tt = pq.top();
15                int server = tt.second;
16                pq.pop();
17                free.insert(server);
18                free.insert(server + k);
19            }
20            if (!free.empty()) {
21                int server = (*free.lower_bound(i % k)) % k;
22                free.erase(server % k);
23                free.erase(server % k + k);
24
25                cnt[server]++;
26                pq.push({at + load, server});
27            }
28        }
29        int mv = -1;
30        vector<int> res;
31        for (int i = 0; i < k; i++) {
32            if (cnt[i] > mv) {
33                mv = cnt[i];
34                res = {i};
35            } else if (cnt[i] == mv)
36                res.push_back(i);
37        }
38        return res;
39    }
40};