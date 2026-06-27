// Last updated: 27/06/2026, 16:44:21
1class Solution {
2public:
3    int countSteps(int ringIndex, int i, int n) {
4        int dist = abs(i - ringIndex);
5        int wrap_around = (n - dist);
6        return min(dist, wrap_around);
7    }
8
9    int findRotateSteps(string ring, string key) {
10        int n = ring.size();
11        int m = key.size();
12
13        unordered_map<char, vector<int>> adj;
14        for (int i = 0; i < n; i++) {
15            char ch = ring[i];
16            adj[ch].push_back(i);
17        }
18
19        priority_queue<pair<int, pair<int, int>>,
20                       vector<pair<int, pair<int, int>>>,
21                       greater<pair<int, pair<int, int>>>>
22            pq;
23
24        pq.push({0, {0, 0}});
25        set<pair<int, int>> visited;
26
27        int totalSteps;
28        while (!pq.empty()) {
29            totalSteps = pq.top().first;
30            int ri = pq.top().second.first;
31            int ki = pq.top().second.second;
32            pq.pop();
33            char curr = key[ki];
34
35            if (ki == m) {
36                break;
37            }
38
39            if (visited.count({ri, ki}))
40                continue;
41
42            visited.insert({ri, ki});
43
44            for (int j = 0; j < adj[curr].size(); j++) {
45                int steps = countSteps(ri, adj[curr][j], n) + totalSteps;
46                pq.push({steps, {adj[curr][j], ki + 1}});
47            }
48        }
49
50        return totalSteps + m;
51    }
52};