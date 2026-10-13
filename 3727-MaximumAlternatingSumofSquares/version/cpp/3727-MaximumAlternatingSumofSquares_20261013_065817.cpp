// Last updated: 13/10/2026, 06:58:17
1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        long long ans = 0;
5
6        sort(nums.begin(), nums.end());
7        int n = nums.size();
8
9        vector<int> v;
10        for (auto it : nums) {
11            v.push_back(abs(it - 0));
12        }
13
14        sort(v.begin(), v.end());
15        int i = 0, j = n - 1;
16        while (i < j) {
17            ans += (v[j] * v[j]);
18            ans -= (v[i] * v[i]);
19            i++;
20            j--;
21        }
22
23        if (i == j) {
24            ans += (v[i] * v[i]);
25        }
26
27        return ans;
28    }
29};