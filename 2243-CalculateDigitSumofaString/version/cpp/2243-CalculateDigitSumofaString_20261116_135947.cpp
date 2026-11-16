// Last updated: 16/11/2026, 13:59:47
1class Solution {
2public:
3    string digitSum(string s, int k) {
4        while(s.size() > k) {
5            string t;
6            for(int i = 0; i < s.size(); i++){
7                int sum = 0, j;
8                for(j = i; j < s.size() && j - i < k; j++){
9                    sum += s[j] - '0';
10                }
11                i = j - 1;
12                t += to_string(sum);
13            }
14            s = t;
15        }
16
17        return s;
18    }
19};