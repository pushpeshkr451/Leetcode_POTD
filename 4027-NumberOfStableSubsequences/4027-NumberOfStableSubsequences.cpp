// Last updated: 09/06/2026, 19:44:36
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;
    int dp[(int)1e5 + 1][4][4];
    int solve(int idx, vector<int>& nums, int cnt, int pre) {
        if (idx == n)
            return 0;

        if (dp[idx][cnt][pre + 1] != -1)
            return dp[idx][cnt][pre + 1];

        long long ans = 0;
        ans += solve(idx + 1, nums, cnt, pre);

        if (pre == -1) {
            // ans += 1;
            ans += 1 + solve(idx + 1, nums, 1, nums[idx] % 2);
        } else {
            if (pre == nums[idx] % 2) {
                if (cnt < 2) {
                    // ans += 1;
                    ans += 1 + solve(idx + 1, nums, cnt + 1, pre);
                }
            } else {
                // ans += 1;
                ans += 1 + solve(idx + 1, nums, 1, nums[idx] % 2);
            }
        }

        return dp[idx][cnt][pre + 1] = ans % mod;
    }

    int countStableSubsequences(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, -1);
    }
};
