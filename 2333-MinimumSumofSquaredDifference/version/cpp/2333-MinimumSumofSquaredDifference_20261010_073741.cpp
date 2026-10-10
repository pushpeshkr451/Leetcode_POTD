// Last updated: 10/10/2026, 07:37:41
1class Solution {
2public:
3    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1,
4                               int k2) {
5        int n = arr1.size(), k = k1 + k2, diff = 0, maxDiff = 0;
6
7        unordered_map<int, int> freq;
8        for (int i = 0; i < n; i++) {
9            diff = abs(arr1[i] - arr2[i]);
10            freq[diff]++;
11            maxDiff = max(diff, maxDiff);
12        }
13
14        while (maxDiff > 0 && k > 0) {
15            if (freq.count(maxDiff)) {
16                int mn = min(k, freq[maxDiff]);
17                k -= mn;
18                freq[maxDiff] -= mn;
19                freq[maxDiff - 1] += mn;
20            }
21
22            maxDiff--;
23        }
24
25        long long res = 0;
26        for (auto it : freq)
27            res += (long long)it.first * it.first * it.second;
28
29        return res;
30    }
31};