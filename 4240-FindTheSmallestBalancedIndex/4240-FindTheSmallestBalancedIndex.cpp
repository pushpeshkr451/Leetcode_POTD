// Last updated: 09/06/2026, 19:43:20
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return -1;
        vector<long long> pre(n), suff(n);

        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        long long limit = 1e18;
        for (int i = n - 2; i >= 0; i--) {
            if (suff[i + 1] > limit / nums[i])
                suff[i] = limit;
            else
                suff[i] = suff[i + 1] * nums[i];
        }
        long long left, right;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left = 0;
                right = suff[1];
            }
            if (i == n - 1) {
                left = pre[n - 2];
                right = 1;
            }
            if (i > 0 && i < n - 1) {
                left = pre[i - 1];
                right = suff[i + 1];
            }
            if (left == right)
                return i;
        }

        return -1;
    }
};