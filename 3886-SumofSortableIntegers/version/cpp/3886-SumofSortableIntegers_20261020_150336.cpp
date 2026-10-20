// Last updated: 20/10/2026, 15:03:36
1class Solution {
2public:
3    bool canRotateSort(vector<int>& a) {
4        int n = a.size();
5        int descents = 0;
6        int start = 0;
7
8        for (int i = 0; i < n; i++) {
9            int j = (i + 1) % n;
10            if (a[i] > a[j]) {
11                descents++;
12                start = j;
13            }
14        }
15
16        return descents <= 1;
17    }
18
19    int sortableIntegers(vector<int>& nums) {
20        int n = nums.size();
21        int ans = 0;
22
23        for (int k = 1; k <= n; k++) {
24            if (n % k != 0) continue;
25
26            bool valid = true;
27            int prevMax = -1;
28
29            for (int i = 0; i < n; i += k) {
30                vector<int> block(nums.begin() + i,
31                                  nums.begin() + i + k);
32
33                if (!canRotateSort(block)) {
34                    valid = false;
35                    break;
36                }
37
38                int mn = *min_element(block.begin(), block.end());
39                int mx = *max_element(block.begin(), block.end());
40
41                if (mn < prevMax) {
42                    valid = false;
43                    break;
44                }
45
46                prevMax = mx;
47            }
48
49            if (valid) ans += k;
50        }
51
52        return ans;
53    }
54};