// Last updated: 18/08/2026, 13:42:44
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        int ans=0;
6
7        for (int i = 0; i < n; i++) {
8            int sum = 0;
9            for (int j = i; j < n; j++) {
10                sum += nums[j];
11                if (sum == k)
12                    ans++;
13                
14            }
15        }
16        return ans;
17    }
18};