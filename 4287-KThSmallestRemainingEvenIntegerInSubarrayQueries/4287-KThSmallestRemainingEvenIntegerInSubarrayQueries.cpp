// Last updated: 09/06/2026, 19:42:34
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> even, even_idx;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(nums[i]);
                even_idx.push_back(i);
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long k = q[2];

            int left = lower_bound(even_idx.begin(), even_idx.end(), l) -
                       even_idx.begin();
            int right = upper_bound(even_idx.begin(), even_idx.end(), r) -
                        even_idx.begin() - 1;
            long long lo = 2, hi = 2e18, res = -1;

            while (lo <= hi) {
                long long mid = (lo + hi) / 2;
                long long total = mid / 2;

                long long removed = 0;
                if (left <= right) {
                    int cnt = upper_bound(even.begin() + left,
                                          even.begin() + right + 1, mid) -
                              (even.begin() + left);
                    removed = cnt;
                }
                long long remaining = total - removed;

                if (remaining >= k) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};