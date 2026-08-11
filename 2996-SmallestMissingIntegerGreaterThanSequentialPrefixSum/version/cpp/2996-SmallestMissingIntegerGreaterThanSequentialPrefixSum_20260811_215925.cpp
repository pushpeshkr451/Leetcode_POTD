// Last updated: 11/08/2026, 21:59:25
1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        set<int> st(nums.begin(), nums.end());
5        int n = nums.size();
6
7        int sum = 0;
8        int ans = INT_MIN;
9
10        for (int i = 0; i < n; i++) {
11            if (i > 0) {
12                if (nums[i] == nums[i - 1] + 1) {
13                    sum += nums[i];
14                } else {
15                   break;
16                }
17            }
18
19            else {
20                sum += nums[i];
21            }
22        }
23        // if(n>1){
24        //     if(nums[n-1]==nums[n-2]+1){
25        //         sum+=nums[i];
26        //         ans=max(ans,sum);
27        //     }
28        //     else{
29
30        //     }
31        // }
32        ans = max(ans, sum);
33        while (st.find(ans) != st.end()) {
34            ans++;
35        }
36
37        return ans;
38    }
39};