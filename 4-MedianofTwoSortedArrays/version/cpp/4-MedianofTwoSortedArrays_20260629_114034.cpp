// Last updated: 29/06/2026, 11:40:34
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        if (nums1.size() > nums2.size()) {
5            return findMedianSortedArrays(nums2, nums1);
6        }
7
8        int len1 = nums1.size(), len2 = nums2.size();
9        int left = 0, right = len1;
10
11        while (left <= right) {
12            int part1 = (left + right) / 2;
13            int part2 = (len1 + len2 + 1) / 2 - part1;
14
15            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
16            int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
17            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
18            int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];
19
20            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
21                if ((len1 + len2) % 2 == 0) {
22                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
23                } else {
24                    return max(maxLeft1, maxLeft2);
25                }
26            } else if (maxLeft1 > minRight2) {
27                right = part1 - 1;
28            } else {
29                left = part1 + 1;
30            }
31        }
32
33        return 0.0;        
34    }
35};