// Last updated: 30/09/2026, 07:53:10
1class Solution {
2public:
3    std::vector<int> maxDepthAfterSplit(std::string& seq) {
4        int n = seq.size();
5        int maxDepth = 0;
6        int depth = 0;
7        for (char c : seq) {
8            if (c == ')') {
9                depth--;
10                continue;
11            }
12            depth++;
13            if (depth > maxDepth) maxDepth = depth;
14        }
15
16        std::vector<int> r(n, 0);
17        int half = maxDepth >> 1;
18
19        depth = 0;
20        for (int i = 0; i < n; i++) {
21            char c = seq[i];
22            if (c == ')') {
23                // Close A first if A has open
24                if (depth > 0) {
25                    depth--;
26                    continue;
27                }
28                r[i] = 1;
29                continue;
30            }
31            // A is full, rest goes to B
32            if (depth >= half) {
33                r[i] = 1;
34                continue;
35            }
36            depth++;
37        }
38        return r;
39    }
40};