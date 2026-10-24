// Last updated: 24/10/2026, 12:21:09
1class Solution {
2public:
3    int countDaysTogether(string arriveAlice, string leaveAlice,
4                          string arriveBob, string leaveBob) {
5        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
6
7        auto convert = [&](string s) {
8            int m = stoi(s.substr(0, 2));
9            int d = stoi(s.substr(3, 2));
10
11            for (int i = 0; i < m - 1; i++) {
12                d += days[i];
13            }
14
15            return d;
16        };
17
18        int a = max(convert(arriveAlice), convert(arriveBob));
19        int b = min(convert(leaveAlice), convert(leaveBob));
20
21        return max(0, b - a + 1);
22    }
23};