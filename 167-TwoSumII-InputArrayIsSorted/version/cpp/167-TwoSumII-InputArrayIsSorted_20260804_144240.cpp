// Last updated: 04/08/2026, 14:42:40
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4
5        int l = 0;
6        int r = numbers.size() - 1;
7
8        while (l < r) {
9
10            int sum = numbers[l] + numbers[r];
11
12            if (sum == target)
13                return {l + 1, r + 1};
14
15            if (sum < target)
16                l++;
17            else
18                r--;
19        }
20
21        return {};
22    }
23};