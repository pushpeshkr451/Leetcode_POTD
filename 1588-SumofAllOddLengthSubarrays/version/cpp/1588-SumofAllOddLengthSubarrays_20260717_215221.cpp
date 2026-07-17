// Last updated: 17/07/2026, 21:52:21
1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4
5        int n = arr.size();
6        int ans = 0;
7
8        for (int i = 0; i < n; i++) {
9
10            int sum = 0;
11
12            for (int j = i; j < n; j++) {
13
14                sum += arr[j];
15
16                if ((j - i + 1) % 2 == 1)
17                    ans += sum;
18            }
19        }
20
21        return ans;
22    }
23};