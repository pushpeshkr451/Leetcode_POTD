// Last updated: 15/07/2026, 02:33:37
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        unordered_map<char, pair<int, int>> mp;
5
6        for (int i = 0; i < s.size(); i++) {
7            mp[s[i]].first++;
8            mp[s[i]].second = i;
9        }
10
11        int ans = INT_MAX;
12
13        for (auto it : mp) {
14            if (it.second.first == 1)
15                ans = min(ans, it.second.second);
16        }
17
18        return ans == INT_MAX ? -1 : ans;
19    }
20};