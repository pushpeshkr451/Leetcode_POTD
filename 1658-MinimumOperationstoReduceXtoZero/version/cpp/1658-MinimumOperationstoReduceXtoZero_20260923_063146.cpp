// Last updated: 23/09/2026, 06:31:46
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        int totalSum = 0;
6
7        for(int i = 0; i<n; i++){
8            totalSum = totalSum + nums[i];
9        }
10
11        if (totalSum < x) {
12            return -1;
13        }
14
15
16        int target = totalSum - x;
17
18        int left = 0;
19        int right = 0;
20        int maxLen = -1;
21        int sum = 0;
22
23        while(right < n){
24            sum = sum + nums[right];
25
26            while(sum > target){
27                sum = sum - nums[left];
28                left++;
29            }
30
31            if(sum == target){
32                maxLen = max(maxLen, right - left + 1);
33            }
34
35            right++;
36        }
37
38        if(maxLen == -1){
39            return -1;
40        }
41        
42        return n - maxLen;
43    }
44};