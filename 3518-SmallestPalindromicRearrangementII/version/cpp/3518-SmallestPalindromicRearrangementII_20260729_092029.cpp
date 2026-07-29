// Last updated: 29/07/2026, 09:20:29
1class Solution {
2public:
3    string smallestPalindrome(string s, int k) {
4        vector<int> freq(26, 0);
5        for (char c : s) {
6            freq[c - 'a']++;
7        }
8        
9        vector<int> half(26, 0);
10        string mid = "";
11        int m = 0;
12        
13        for (int i = 0; i < 26; ++i) {
14            if (freq[i] % 2 != 0) {
15                mid += (char)(i + 'a');
16            }
17            half[i] = freq[i] / 2;
18            m += half[i];
19        }
20        
21        auto get_ways = [&](const vector<int>& f, long long target_k) {
22            long long ways = 1;
23            int curr_len = 0;
24            for (int count : f) {
25                if (count > 0) {
26                    curr_len += count;
27                    long long n = curr_len;
28                    long long r = count;
29                    
30                    if (r > n - r) r = n - r;
31                    long long cur_nCr = 1;
32                    
33                    for (int i = 1; i <= r; ++i) {
34                        cur_nCr = cur_nCr * (n - i + 1) / i;
35                        if (cur_nCr > target_k) {
36                            cur_nCr = target_k + 1;
37                            break;
38                        }
39                    }
40                    ways *= cur_nCr;
41                    if (ways > target_k) return target_k + 1;
42                }
43            }
44            return ways;
45        };
46        
47        if (get_ways(half, k) < k) {
48            return "";
49        }
50        
51        string first_half = "";
52        for (int i = 0; i < m; ++i) {
53            for (int c = 0; c < 26; ++c) {
54                if (half[c] > 0) {
55                    half[c]--;
56                    long long ways = get_ways(half, k);
57                    
58                    if (ways >= k) {
59                        first_half += (char)(c + 'a');
60                        break; 
61                    } else {
62                        k -= ways;
63                        half[c]++;
64                    }
65                }
66            }
67        }
68        
69        string res = first_half + mid;
70        for (int i = m - 1; i >= 0; --i) {
71            res += first_half[i];
72        }
73        return res;
74    }
75};