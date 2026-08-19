// Last updated: 19/08/2026, 13:10:47
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4
5        sort(reservedSeats.begin(), reservedSeats.end());
6
7        int ans = 0;
8        int cnt = 1;
9
10        vector<bool> check(11, false);
11
12        for (int i = 0; i < reservedSeats.size(); ) {
13
14            int row = reservedSeats[i][0];
15
16            // Empty rows before this row
17            ans += (row - cnt) * 2;
18
19            check.assign(11, false);
20
21            // Process all reserved seats of this row
22            while (i < reservedSeats.size() && reservedSeats[i][0] == row) {
23                check[reservedSeats[i][1]] = true;
24                i++;
25            }
26
27            bool left = false;
28            bool middle = false;
29            bool right = false;
30
31            // 2,3,4,5
32            for (int j = 2; j <= 5; j++) {
33                if (check[j]) {
34                    left = true;
35                    break;
36                }
37            }
38
39            // 4,5,6,7
40            for (int j = 4; j <= 7; j++) {
41                if (check[j]) {
42                    middle = true;
43                    break;
44                }
45            }
46
47            // 6,7,8,9
48            for (int j = 6; j <= 9; j++) {
49                if (check[j]) {
50                    right = true;
51                    break;
52                }
53            }
54
55            if (!left && !right) {
56                ans += 2;
57            }
58            else if (!left || !middle || !right) {
59                ans++;
60            }
61
62            cnt = row + 1;
63        }
64
65        // Empty rows after the last reserved row
66        ans += (n - cnt + 1) * 2;
67
68        return ans;
69    }
70};