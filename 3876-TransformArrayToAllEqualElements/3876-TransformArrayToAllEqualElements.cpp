// Last updated: 09/06/2026, 19:45:43
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v = nums;
        int cnt_1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == -1) {
                nums[i] *= -1;
                nums[i + 1] *= -1;
                cnt_1++;
            }
        }
        int cnt_2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 1) {
                v[i] *= -1;
                v[i + 1] *= -1;
                cnt_2++;
            }
        }
        bool flag1 = false, flag2 = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                flag1 = true;
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (v[i] != v[i + 1]) {
                flag2 = true;
                break;
            }
        }
        if (!flag1 && !flag2) {
            return min(cnt_1, cnt_2) <= k;
        }
        if (!flag1 && cnt_1 <= k)
            return true;
        if (!flag2 && cnt_2 <= k)
            return true;
        return false;
    }
};