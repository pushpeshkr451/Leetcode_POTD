// Last updated: 01/08/2026, 11:12:31
1class Solution {
2public:
3int solve(int i, int j, vector<int>& nums, bool flag) {
4    if (i > j) return 0;
5
6    if (flag) {
7        // Player1's turn: maximize score
8        int pickLeft = nums[i] + solve(i+1, j, nums, false);
9        int pickRight = nums[j] + solve(i, j-1, nums, false);
10        return max(pickLeft, pickRight);
11    } else {
12        // Player2's turn: minimize Player1's score
13        int pickLeft = solve(i+1, j, nums, true);
14        int pickRight = solve(i, j-1, nums, true);
15        return min(pickLeft, pickRight);
16    }
17}
18
19bool predictTheWinner(vector<int>& nums) {
20    int total = solve(0, nums.size()-1, nums, true);
21    int sum = 0;
22    for (int x : nums) sum += x;
23    return total >= sum - total;
24}
25};
26