// Last updated: 30/06/2026, 13:34:53
1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int count = 0;
5        int left = 0;
6        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
7        
8        for (int right = 0; right < s.length(); ++right) {
9            char_count[s[right]]++;
10            
11            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
12                count += s.length() - right;
13                char_count[s[left]]--;
14                left++;
15            }
16        }
17        
18        return count;
19    }
20};