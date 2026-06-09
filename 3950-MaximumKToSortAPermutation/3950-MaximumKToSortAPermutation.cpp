// Last updated: 09/06/2026, 19:45:06
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int k = -1;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                ok = false;
                k &= (i & nums[i]);
            }
        }
        if (ok) return 0;
        return k;
    }
};