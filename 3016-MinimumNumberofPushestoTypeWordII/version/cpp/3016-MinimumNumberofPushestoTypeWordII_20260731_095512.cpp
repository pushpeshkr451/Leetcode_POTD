// Last updated: 31/07/2026, 09:55:12
1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int> freq(26, 0);
5
6        for (char ch : word) {
7            freq[ch - 'a']++;
8        }
9
10        sort(freq.begin(), freq.end(), greater<int>());
11
12        int ans = 0;
13
14        for (int i = 0; i < 26; i++) {
15            if (freq[i] == 0) break;
16
17            int pushes = (i / 8) + 1;
18
19            ans += freq[i] * pushes;
20        }
21
22        return ans;
23    }
24};