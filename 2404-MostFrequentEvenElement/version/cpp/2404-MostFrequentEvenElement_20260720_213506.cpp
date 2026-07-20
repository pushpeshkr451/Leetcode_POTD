// Last updated: 20/07/2026, 21:35:06
1class Solution {
2public:
3    int mostFrequentEven(vector<int>& nums) {
4        map<int, int> freq;
5
6        for (int num : nums) {
7            if (num % 2 == 0)
8                freq[num]++;
9        }
10
11        int ans = -1;
12        int maxFreq = 0;
13
14        for (auto &[num, cnt] : freq) {
15            if (cnt > maxFreq) {
16                maxFreq = cnt;
17                ans = num;
18            }
19        }
20
21        return ans;
22    }
23};