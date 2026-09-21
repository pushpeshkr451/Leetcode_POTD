// Last updated: 21/09/2026, 13:17:35
1class Solution {
2public:
3    vector<long long> resultArray(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<long long> pre(k, 0);
6        vector<long long> result(k), preff(k), suff(k);
7        for (int i = 0; i < n; ++i) {
8            int m = nums[i] % k;
9            suff = pre;
10            for (int j = 0; j < k;j++)
11                suff[(int)((j * m) % k)] += preff[j];
12            suff[m]++;
13            for (int l = 0; l < k;l++)
14                result[l] += suff[l];
15            preff.swap(suff);
16        }
17        return result;
18    }
19};