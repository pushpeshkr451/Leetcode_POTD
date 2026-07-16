// Last updated: 16/07/2026, 14:39:44
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5
6        int mx = nums[0];
7
8        vector<int> arr(n);
9        arr[0] = nums[0];
10        for (int i = 1; i < n; i++) {
11
12            mx = max(nums[i], mx);
13            arr[i] = __gcd(nums[i], mx);
14        }
15
16        // for (auto it : arr) {
17        //     cout << it << " ";
18        // }
19        // cout << endl;
20
21        sort(arr.begin(), arr.end());
22
23        // for (auto it : arr) {
24        //     cout << it << " ";
25        // }
26
27        int i = 0, j = n - 1;
28        long long ans = 0;
29        while (i < j) {
30            ans = ans + __gcd(arr[i], arr[j]);
31            i++;
32            j--;
33        }
34
35        return ans;
36    }
37};