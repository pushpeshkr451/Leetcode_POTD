// Last updated: 06/10/2026, 06:21:44
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4
5        int count = 0;
6        int charCount = 0;
7
8        for (int i = 0; i < s.length(); i++) {
9
10            if (s[i] == '(')
11                charCount++;
12
13            if (s[i] == ')') {
14
15                if (charCount == 0) {
16                    count++;
17                } else {
18                    charCount--;
19                }
20            }
21        }
22
23        return count + charCount;
24    }
25};