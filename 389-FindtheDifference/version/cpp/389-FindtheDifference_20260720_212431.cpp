// Last updated: 20/07/2026, 21:24:31
1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        unordered_map<char, int> mp;
5
6        for (auto it : s)
7            mp[it]++;
8        for (auto it : t) {
9            mp[it]--;
10            if (mp[it] == 0)
11                mp.erase(it);
12        }
13        char ans;
14        for (auto it : mp)
15            ans = it.first;
16
17        return ans;
18    }
19};