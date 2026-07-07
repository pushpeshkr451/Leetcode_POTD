// Last updated: 07/07/2026, 13:14:41
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        long long sum = 0;
5        string ans = "";
6        string s = to_string(n);
7
8        for (auto it : s) {
9            if (it - '0' > 0) {
10                sum += (it - '0');
11                ans += it;
12            }
13        }
14        if(ans.empty())return 0;
15        long long res = stoi(ans) * sum;
16
17        return res;
18    }
19};