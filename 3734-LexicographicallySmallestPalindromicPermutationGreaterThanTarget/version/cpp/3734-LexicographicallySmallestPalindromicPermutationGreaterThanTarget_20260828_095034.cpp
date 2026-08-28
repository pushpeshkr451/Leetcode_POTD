// Last updated: 28/08/2026, 09:50:34
1class Solution {
2public:
3    string lexPalindromicPermutation(string s, string target) {
4        int cnt[26]{}, n = s.size();
5        for (char c : s) {
6            ++cnt[c - 'a'];
7        }
8        string res(n, '#');
9        // check palindrome and set middle if odd.
10        for (int i = 0; i < 26; ++i) {
11            if (!(cnt[i] & 1)) continue;
12            if (res[n / 2] != '#') return "";
13            res[n / 2] = 'a' + i;
14        }
15
16        int m = n / 2;
17        auto dfs = [&] (this auto&& dfs, int i, bool big) -> bool {
18            if (i == m) return (big || res > target);
19            int base = target[i] - 'a';
20            for (int j = big ? 0 : base; j < 26; ++j) {
21                if (cnt[j] < 2) continue;
22                cnt[j] -= 2;
23                res[i] = res[n - 1 - i] = 'a' + j;
24                if (dfs(i + 1, big || j > base)) return true;
25                cnt[j] += 2;
26            }
27            return false;
28        };
29
30        if (!dfs(0, false)) return "";
31        return res;
32    }
33};