// Last updated: 28/11/2026, 10:55:27
1class Solution {
2public:
3    int maximumSaleItems(vector<vector<int>>& items, int budget) {
4        int n = items.size();
5
6        long long mn = 2e18;
7        vector<int> freq(n + 1, 0);
8
9        for (auto& it : items) {
10            freq[it[0]]++;
11            mn = min(mn, (long long)it[1]);
12        }
13
14        vector<int> dp(n + 1, 0);
15        for (int i = 1; i <= n; i++) {
16            if (freq[i] == 0)
17                continue;
18
19            int cnt = 0;
20            for (int j = i; j <= n; j += i) {
21                cnt += freq[j];
22            }
23            dp[i] = cnt - 1;
24        }
25
26        vector<pair<long long, long long>> v;
27
28        for (auto& it : items) {
29            long long fir = it[0];
30            long long sec = it[1];
31
32            if (dp[fir] > 0 && sec < 2 * mn) {
33                v.push_back({sec, dp[fir]});
34            }
35        }
36
37        sort(v.begin(), v.end());
38
39        long long b = budget;
40        long long ans = 0;
41
42        for (auto& it : v) {
43            long long fir = it.first;
44            long long cnt = it.second;
45
46            if (b < fir)
47                break;
48
49            long long take = min(cnt, b / fir);
50            ans += 2 * take;
51            b -= take * fir;
52        }
53
54        ans += b / mn;
55
56        return ans;
57    }
58};