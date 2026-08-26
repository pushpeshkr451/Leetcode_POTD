// Last updated: 26/08/2026, 13:47:32
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        string answer = "";
5        int left = 0;
6        int ones = 0;
7
8        for (int right = 0; right < s.size(); right++) {
9            if (s[right] == '1') {
10                ones++;
11            }
12
13            while (ones > k) {
14                if (s[left] == '1') {
15                    ones--;
16                }
17                left++;
18            }
19
20            while (ones == k && s[left] == '0') {
21                left++;
22            }
23
24            if (ones == k) {
25                int length = right - left + 1;
26
27                string candidate = s.substr(left, length);
28
29                if (answer.empty() ||
30                    candidate.size() < answer.size() ||
31                    (candidate.size() == answer.size() && candidate < answer)) {
32                    answer = candidate;
33                }
34            }
35        }
36
37        return answer;
38    }
39};