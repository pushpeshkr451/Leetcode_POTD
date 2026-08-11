// Last updated: 11/08/2026, 22:00:46
1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        int n=nums.size();
5        set<int>st(nums.begin(),nums.end());
6        int sum = nums[0];
7
8        for (int i = 1; i < n; i++) {
9            if (nums[i] == nums[i - 1] + 1)
10                sum += nums[i];
11            else
12                break;
13        }
14
15        while (st.find(sum) != st.end())
16            sum++;
17
18        return sum;
19    }
20};