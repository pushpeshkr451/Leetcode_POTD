// Last updated: 19/08/2026, 13:11:08
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        int left = 0b11110000;
5        int middle = 0b11000011;
6        int right = 0b00001111;
7
8        unordered_map<int, int> occupied;
9        for (const vector<int>& seat : reservedSeats) {
10            if (seat[1] >= 2 && seat[1] <= 9) {
11                occupied[seat[0]] |= (1 << (seat[1] - 2));
12            }
13        }
14
15        int ans = (n - occupied.size()) * 2;
16        for (auto& [row, bitmask] : occupied) {
17            if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
18                ((bitmask | right) == right)) {
19                ++ans;
20            }
21        }
22        return ans;
23    }
24};