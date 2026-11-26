// Last updated: 26/11/2026, 14:55:06
1class Solution {
2public:
3    bool canAliceWin(int n) {
4        int remove = 10;
5        bool aliceTurn = true;
6        while (n >= remove) {
7            n -= remove;
8            remove--;
9            aliceTurn = !aliceTurn;
10        }
11        return !aliceTurn;
12    }
13};