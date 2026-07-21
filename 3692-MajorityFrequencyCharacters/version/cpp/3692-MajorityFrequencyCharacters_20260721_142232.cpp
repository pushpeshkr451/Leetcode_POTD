// Last updated: 21/07/2026, 14:22:32
1class Solution {
2public:
3    string majorityFrequencyGroup(string s) {
4        vector<int> cnt(26, 0);
5
6        // Count frequency of each character
7        for (char c : s)
8            cnt[c - 'a']++;
9
10        // Group characters by their frequency
11        unordered_map<int, string> groups;
12        for (int i = 0; i < 26; i++) {
13            if (cnt[i] > 0)
14                groups[cnt[i]].push_back('a' + i);
15        }
16
17        string ans;
18        int maxGroupSize = 0;
19        int maxFreq = 0;
20
21        // Find the majority frequency group
22        for (auto &[freq, chars] : groups) {
23            if (chars.size() > maxGroupSize ||
24                (chars.size() == maxGroupSize && freq > maxFreq)) {
25                maxGroupSize = chars.size();
26                maxFreq = freq;
27                ans = chars;
28            }
29        }
30
31        return ans;
32    }
33};