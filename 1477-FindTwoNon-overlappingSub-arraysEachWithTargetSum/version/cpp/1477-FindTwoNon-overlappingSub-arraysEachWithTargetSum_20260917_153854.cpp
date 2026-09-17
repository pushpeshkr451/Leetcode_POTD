// Last updated: 17/09/2026, 15:38:54
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        int n = arr.size();
5
6        vector<int> prefsum(n, 0);
7        prefsum[0] = arr[0];
8
9        for (int i = 1; i < n; i++) {
10            prefsum[i] = arr[i] + prefsum[i - 1];
11        }
12
13        vector<pair<int, int>> store;
14
15        for (int i = 0; i < n; i++) {
16            int prevsum = i == 0 ? 0 : prefsum[i - 1];
17
18            int low = i;
19            int high = n - 1;
20
21            while (low <= high) {
22                int mid = low + (high - low) / 2;
23
24                int lastsum = prefsum[mid];
25                int diff = lastsum - prevsum;
26
27                if (diff >= target) {
28                    high = mid - 1;
29
30                    if (diff == target) {
31                        store.push_back({i, mid});
32                    }
33                } else {
34                    low = mid + 1;
35                }
36            }
37        }
38
39        if (store.size() <= 1) return -1;
40
41        sort(store.begin(), store.end());
42
43        vector<pair<int, int>> store2;
44        store2.push_back(store[0]);
45
46        for (int i = 1; i < store.size(); i++) {
47            if (store[i].first != store[i - 1].first) {
48                store2.push_back(store[i]);
49            }
50        }
51
52        int ans = 1e9;
53        int best = 1e9;
54        int j = 0;
55
56        for (int i = 0; i < store2.size(); i++) {
57            while (j < i && store2[j].second < store2[i].first) {
58                best = min(best, store2[j].second - store2[j].first + 1);
59                j++;
60            }
61
62            if (best != 1e9) {
63                int len = store2[i].second - store2[i].first + 1;
64                ans = min(ans, best + len);
65            }
66        }
67
68        return ans == 1e9 ? -1 : ans;
69    }
70};