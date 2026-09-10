// Last updated: 10/09/2026, 20:00:59
1class Solution {
2public:
3    int smallestDistancePair(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5
6        int n = nums.size();
7
8        int low = 0;
9        int high = nums[n - 1] - nums[0];
10
11        while(low < high) {
12            int mid = low + (high - low) / 2;
13
14            int left = 0;
15            int count = 0;
16
17            for(int right = 0; right < n; right++) {
18                while(nums[right] - nums[left] > mid) {
19                    left++;
20                }
21
22                count += right - left;
23            }
24
25            if(count >= k) {
26                high = mid;
27            }
28            else {
29                low = mid + 1;
30            }
31        }
32
33        return low;
34    }
35};