// Last updated: 22/07/2026, 13:55:28
1class Solution {
2public:
3    int similarPairs(vector<string>& words) {
4        int n = words.size();
5        int ans = 0;
6
7        vector<set<char>> st(n);
8
9        for (int i = 0; i < n; i++) {
10            for (char c : words[i]) {
11                st[i].insert(c);
12            }
13        }
14
15        for (int i = 0; i < n; i++) {
16            for (int j = i + 1; j < n; j++) {
17                if (st[i] == st[j])
18                    ans++;
19            }
20        }
21
22        return ans;
23    }
24};