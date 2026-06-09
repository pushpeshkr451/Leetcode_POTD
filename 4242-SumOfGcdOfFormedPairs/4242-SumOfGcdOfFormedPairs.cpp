// Last updated: 09/06/2026, 19:43:17
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = nums[0];

        vector<int> arr(n);
        arr[0] = nums[0];
        for (int i = 1; i < n; i++) {

            mx = max(nums[i], mx);
            arr[i] = __gcd(nums[i], mx);
        }

        // for (auto it : arr) {
        //     cout << it << " ";
        // }
        // cout << endl;

        sort(arr.begin(), arr.end());

        // for (auto it : arr) {
        //     cout << it << " ";
        // }

        int i = 0, j = n - 1;
        long long ans = 0;
        while (i < j) {
            ans = ans + __gcd(arr[i], arr[j]);
            i++;
            j--;
        }

        return ans;
    }
};