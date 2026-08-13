// Last updated: 13/08/2026, 22:15:39
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        // Set the left and right boundaries
5        int left = 0, right = int(nums.size()) - 1;
6        
7        // Under this condition
8        while (left <= right) {
9            // Get the middle index and the middle value.
10            int mid = left + (right - left) / 2;
11            
12            // Case 1, return the middle index.
13            if (nums[mid] == target) {
14                return mid;
15            } 
16            // Case 2, discard the smaller half.
17            else if (nums[mid] < target) {
18                left = mid + 1;   
19            } 
20            // Case 3, discard the larger half.
21            else {
22                right = mid - 1;
23            }
24        }
25        
26        // If we finish the search without finding target, return -1.
27        return -1;
28    }
29};