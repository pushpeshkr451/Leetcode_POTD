// Last updated: 25/09/2026, 13:43:35
1class Solution {
2public:
3    string getWord(const string& expr, int& i) {
4        string res;
5        while ('a' <= expr[i] && expr[i] <= 'z')
6            res.push_back(expr[i++]);
7        return res;
8    }
9
10    unordered_set<string> dfs(const string& expr, int& i) {
11        unordered_set<string> res;
12
13        unordered_set<string> S;
14        while (i < int(expr.length()) && expr[i] != '}') {
15            if (expr[i] == ',') {
16                // union
17                for (auto& it : S)
18                    res.insert(it);
19                S.clear();
20                i++;
21            }
22            unordered_set<string> t;
23            if (expr[i] == '{') {
24                i++;
25                t = dfs(expr, i);
26                i++;
27            } else {
28                t.insert(getWord(expr, i));
29            }
30
31            if (S.empty())
32                S = t;
33            else {
34                // cartesian product
35                unordered_set<string> S2;
36                for (auto& it1 : S) {
37                    for (auto& it2 : t)
38                        S2.insert(it1 + it2);
39                }
40                swap(S, S2);
41            }
42        }
43        // union
44        for (auto& it : S)
45            res.insert(it);
46
47        return res;
48    }
49
50    vector<string> braceExpansionII(string expression) {
51        int i = 0;
52        unordered_set<string> S = dfs(expression, i);
53
54        vector<string> res;
55        for (auto& it : S)
56            res.push_back(it);
57        sort(res.begin(), res.end());
58
59        return res;
60    }
61};