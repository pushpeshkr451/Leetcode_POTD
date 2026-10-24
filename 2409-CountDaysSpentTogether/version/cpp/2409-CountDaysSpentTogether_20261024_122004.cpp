// Last updated: 24/10/2026, 12:20:04
1class Solution {
2public:
3    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
4        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
5
6        auto convert = [&](string s) {
7            int m = stoi(s.substr(0, 2));
8            int d = stoi(s.substr(3, 2));
9
10            for (int i = 0; i < m - 1; i++) {
11                d += days[i];
12            }
13
14            return d;
15        };
16
17        int a = max(convert(arriveAlice), convert(arriveBob));
18        int b = min(convert(leaveAlice), convert(leaveBob));
19
20        return max(0, b - a + 1);
21    }
22};