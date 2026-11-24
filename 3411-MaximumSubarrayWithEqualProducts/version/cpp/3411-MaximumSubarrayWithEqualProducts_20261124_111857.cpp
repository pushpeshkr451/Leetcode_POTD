// Last updated: 24/11/2026, 11:18:57
1class Solution {
2public:
3    int findLCM(int a, int b) {
4        return (a / gcd(a, b)) * b;
5    }
6
7    int maxLength(vector<int>& nums) {
8        int n = nums.size();
9        int ans = 0;
10
11        for (int i = 0; i < n; i++) {
12            int gcdValue = nums[i];
13            int lcmValue = nums[i];
14            long long product = nums[i];
15
16            for (int j = i; j < n; j++) {
17                if (j > i) {
18                    gcdValue = gcd(gcdValue, nums[j]);
19                    lcmValue = findLCM(lcmValue, nums[j]);
20                    if (product > LLONG_MAX / nums[j]) {
21                        break;
22                    }
23                    product *= nums[j];
24                }
25
26                if (product == (long long)lcmValue * gcdValue) {
27                    ans = max(ans, j - i + 1);
28                }
29            }
30        }
31
32        return ans;
33    }
34};