// Last updated: 11/09/2026, 15:01:48
1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        set<int> st;
5        int n = digits.size();
6        for (int i = 0; i < n; i++) {
7            if (digits[i] == 0)
8                continue;
9            for (int j = 0; j < n; j++) {
10                if (j == i)
11                    continue;
12                for (int k = 0; k < n; k++) {
13                    if (k == i || k == j)
14                        continue;
15                    if (digits[k] % 2 == 1)
16                        continue;
17                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
18                    st.insert(num);
19                }
20            }
21        }
22
23        return st.size();
24    }
25};