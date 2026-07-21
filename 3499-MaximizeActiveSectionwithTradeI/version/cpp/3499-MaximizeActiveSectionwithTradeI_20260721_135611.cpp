// Last updated: 21/07/2026, 13:56:11
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int one = count(s.begin(), s.end(), '1');
5        string t = "1" + s + "1";
6        vector<pair<char, int>> runs;
7        
8        if (t.empty()) return one;
9        
10        char current = t[0];
11        int cnt = 1;
12        for (int i = 1; i < t.size(); ++i) {
13            if (t[i] == current) {
14                cnt++;
15            } else {
16                runs.emplace_back(current, cnt);
17                current = t[i];
18                cnt = 1;
19            }
20        }
21        runs.emplace_back(current, cnt);
22        
23        int ans = 0;
24        for (int i = 0; i < runs.size(); ++i) {
25            if (runs[i].first == '1') {
26                if (i > 0 && i < runs.size() - 1 && runs[i-1].first == '0' && runs[i+1].first == '0') {
27                    int pans = runs[i-1].second + runs[i+1].second;
28                    if (pans > ans) {
29                        ans = pans;
30                    }
31                }
32            }
33        }
34        
35        return one + ans;
36    }
37};