class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            sum += nums[i];
            int nsum = 0;
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    nsum += nums[j];
                }
                if (sum == nsum)
                    ans += 2;
                else if (sum == nsum + 1 || sum + 1 == nsum)
                    ans++;
            }
        }
        return ans;
    }
};
