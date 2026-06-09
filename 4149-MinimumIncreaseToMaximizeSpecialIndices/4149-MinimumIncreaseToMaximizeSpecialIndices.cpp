// Last updated: 09/06/2026, 19:43:46
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> cost(n, 0);
        for (int i = 1; i < n - 1; i++) {
            int req = max(nums[i - 1], nums[i + 1]) + 1;
            cost[i] = max(0, req - nums[i]);
        }

        vector<pair<int, long long>> dp(n);

        dp[0] = {0, 0};

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if (i > 0 && i < n - 1) {
                pair<int, long long> take = {1, cost[i]};

                if (i >= 2) {
                    take.first += dp[i - 2].first;
                    take.second += dp[i - 2].second;
                }
                if (take.first > dp[i].first ||
                    (take.first == dp[i].first && take.second < dp[i].second)) {
                    dp[i] = take;
                }
            }
        }

        return dp[n - 1].second;
    }
};