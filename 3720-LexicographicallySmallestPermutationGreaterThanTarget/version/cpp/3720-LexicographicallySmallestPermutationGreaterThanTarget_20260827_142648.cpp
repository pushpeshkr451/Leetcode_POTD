// Last updated: 27/08/2026, 14:26:48
1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        int n = s.size();
5
6        vector<int> total(26, 0);
7        for (char c : s) {
8            total[c - 'a']++;
9        }
10
11        vector<int> used(26, 0);
12
13        int i = 0;
14
15        while (i < n) {
16            int c = target[i] - 'a';
17
18            if (used[c] == total[c]) {
19                break;
20            }
21
22            used[c]++;
23            i++;
24        }
25
26        while (i >= 0) {
27            if (i < n) {
28                int current = target[i] - 'a';
29
30                for (int next = current + 1; next < 26; next++) {
31                    if (used[next] == total[next]) {
32                        continue;
33                    }
34
35                    string answer = target.substr(0, i);
36                    answer += char('a' + next);
37
38                    for (int c = 0; c < 26; c++) {
39                        int remaining = total[c] - used[c];
40
41                        if (c == next) {
42                            remaining--;
43                        }
44
45                        answer += string(remaining, char('a' + c));
46                    }
47
48                    return answer;
49                }
50            }
51
52            if (i > 0) {
53                used[target[i - 1] - 'a']--;
54            }
55
56            i--;
57        }
58
59        return "";
60    }
61};