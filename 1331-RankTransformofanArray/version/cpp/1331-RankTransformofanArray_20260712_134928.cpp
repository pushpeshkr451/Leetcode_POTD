// Last updated: 12/07/2026, 13:49:28
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        set<int> st(arr.begin(), arr.end());
5
6        unordered_map<int, int> rank;
7        int r = 1;
8
9        for (int x : st) {
10            rank[x] = r++;
11        }
12
13        for (int &x : arr) {
14            x = rank[x];
15        }
16
17        return arr;
18    }
19};