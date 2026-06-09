// Last updated: 09/06/2026, 19:43:39
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        
        int n = nums.size();

        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        vector<long long> suff(n);
        suff[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            suff[i] = min(suff[i+1], (long long)nums[i]);
        }

        long long ans = LLONG_MIN;

        for(int i = 0; i < n-1; i++){
            ans = max(ans, pre[i] - suff[i+1]);
        }

        return ans;
    }
};