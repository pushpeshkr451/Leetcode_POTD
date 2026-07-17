// Last updated: 17/07/2026, 21:01:34
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int maxVal = *max_element(nums.begin(), nums.end());
5
6        // frequency of x
7        vector<long long> freq(maxVal + 1, 0);
8        for (int x : nums)
9            freq[x]++;
10
11        // divCnt[g] stores the freq of numbers divisible by g
12        vector<long long> divCnt(maxVal + 1, 0);
13
14        for (int g = 1; g <= maxVal; g++) {
15            for (int x = g; x <= maxVal; x += g)
16                divCnt[g] += freq[x];
17        }
18
19        // exact[g] is the number of pairs whose gcd is exactly g
20        vector<long long> exact(maxVal + 1, 0);
21
22        for (int g = maxVal; g >= 1; g--) {
23            exact[g] = divCnt[g] * (divCnt[g] - 1) / 2; //pairing of all numbers divisible by g
24        // it may be possible that two numbers are divisble by x but their gcd is not exactly x, it can be k*x so we have to remove those pairs
25            for (int m = 2 * g; m <= maxVal; m += g)
26                exact[g] -= exact[m];
27        }
28
29        // prefix[g] => pairs with gcd <= g
30        vector<long long> prefix(maxVal + 1, 0);
31        for (int g = 1; g <= maxVal; g++)
32            prefix[g] = prefix[g - 1] + exact[g];
33
34        vector<int> ans;
35
36        for (long long q : queries) {
37            // first gcd whose prefix > q
38            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
39            ans.push_back(g);
40        }
41
42        return ans;
43    }
44};