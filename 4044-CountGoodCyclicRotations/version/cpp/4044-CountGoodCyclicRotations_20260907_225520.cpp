// Last updated: 07/09/2026, 22:55:20
1class Solution {
2public:
3    int countGoodRotations(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> temp = nums;
7        temp.insert(temp.end(), nums.begin(), nums.end());
8
9        long long sum1 = 0, sum2 = 0;
10
11        for (int i = 0; i < n / 2; i++) {
12            sum1 += nums[i];
13        }
14
15        long long total = accumulate(nums.begin(), nums.end(), 0LL);
16
17        sum2 = total - sum1;
18
19        int a = 0;
20        int b = (n / 2) - 1;
21        int c = n / 2;
22        int d = n - 1;
23
24        int ans = 0;
25
26        if (sum1 > sum2)
27            ans++;
28
29        for (int i = 1; i < n; i++) {
30
31            sum1 -= temp[a++];
32            sum1 += temp[++b];
33
34            sum2 -= temp[c++];
35            sum2 += temp[++d];
36
37            if (sum1 > sum2)
38                ans++;
39        }
40
41        return ans;
42    }
43};