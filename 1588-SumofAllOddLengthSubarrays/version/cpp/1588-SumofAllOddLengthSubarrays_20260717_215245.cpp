// Last updated: 17/07/2026, 21:52:45
1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4
5        int n = arr.size();
6        vector<int> prefix(n + 1, 0);
7
8        for (int i = 0; i < n; i++) {
9            prefix[i + 1] = prefix[i] + arr[i];
10        }
11
12        int ans = 0;
13
14        for (int i = 0; i < n; i++) {
15            for (int j = i; j < n; j++) {
16
17                if ((j - i + 1) % 2 == 1) {
18                    ans += prefix[j + 1] - prefix[i];
19                }
20            }
21        }
22
23        return ans;
24    }
25};