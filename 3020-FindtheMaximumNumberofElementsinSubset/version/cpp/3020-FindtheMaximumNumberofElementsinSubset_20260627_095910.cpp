// Last updated: 27/06/2026, 09:59:10
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<long long, int> mp;
5
6        for (int x : nums)
7            mp[x]++;
8 
9        int ans = 1;
10
11        if (mp.count(1)) {
12            int cnt = mp[1];
13            ans = max(ans, cnt % 2 ? cnt : cnt - 1);
14        }
15
16        for (auto &[num, f] : mp) {
17            if (num == 1) continue;
18
19            long long x = num;
20            int len = 0;
21
22            while (mp.count(x) && mp[x] >= 2) {
23                len += 2;
24
25                if (x > 1e9) break; 
26                x = x * x;
27            }
28
29            if (mp.count(x))
30                len++;
31
32            else
33                len--;
34
35            ans = max(ans, len);
36        }
37
38        return ans;
39    }
40};