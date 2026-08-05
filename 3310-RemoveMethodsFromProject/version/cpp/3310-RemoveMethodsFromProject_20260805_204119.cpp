// Last updated: 05/08/2026, 20:41:19
1constexpr int MAXN = 100005;
2
3class Solution {
4public:
5    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
6        vector<vector<int>> edges(n);
7        vector<int> inDegree(n, 0);
8
9        bitset<MAXN> sus;
10
11        for (const auto& inv : invocations) {
12            edges[inv[0]].push_back(inv[1]);
13            inDegree[inv[1]]++;
14        }
15
16        queue<int> q;
17        q.push(k);
18
19        sus.set(k);
20
21        while (!q.empty()) {
22            int u = q.front();
23            q.pop();
24            for (int v : edges[u]) {
25                inDegree[v]--;
26
27                if (!sus.test(v)) {
28                    q.push(v);
29                    sus.set(v);
30                }
31            }
32        }
33
34        bool canRemoveAll = true;
35        vector<int> rem;
36
37        for (int i = 0; i < n; i++) {
38            if (sus.test(i) && inDegree[i] > 0) {
39                canRemoveAll = false;
40                break;
41            } else if (!sus.test(i)) {
42                rem.push_back(i);
43            }
44        }
45
46        if (!canRemoveAll) {
47            vector<int> allNodes(n);
48            iota(allNodes.begin(), allNodes.end(), 0);
49            return allNodes;
50        }
51
52        return rem;
53    }
54};