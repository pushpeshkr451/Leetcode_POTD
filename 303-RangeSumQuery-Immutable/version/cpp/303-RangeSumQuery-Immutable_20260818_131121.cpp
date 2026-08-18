// Last updated: 18/08/2026, 13:11:21
1class NumArray {
2public:
3    vector<int> pref;
4    NumArray(vector<int>& nums) {
5        int n = nums.size();
6        pref.reserve(n);
7        pref[0] = nums[0];
8
9        for (int i = 1; i < n; i++) {
10            pref[i] = pref[i - 1] + nums[i];
11        }
12    }
13
14    int sumRange(int left, int right) {
15        int lsum = 0, rsum = 0;
16        if (left == 0)
17            rsum = pref[right];
18        else {
19            lsum = pref[left - 1];
20            rsum = pref[right];
21        }
22
23        return rsum - lsum;
24    }
25};
26
27/**
28 * Your NumArray object will be instantiated and called as such:
29 * NumArray* obj = new NumArray(nums);
30 * int param_1 = obj->sumRange(left,right);
31 */