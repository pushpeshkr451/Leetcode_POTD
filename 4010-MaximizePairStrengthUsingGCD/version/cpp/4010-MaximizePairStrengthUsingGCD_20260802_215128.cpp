// Last updated: 02/08/2026, 21:51:28
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int overall_g = nums[0];
        for( int x : nums){
            overall_g = gcd(overall_g, x);
        }
        vector<int> unique_nums;
        unique_nums.reserve(nums.size());
        for( int x : nums){
            unique_nums.push_back(x / overall_g);
        }
        sort(unique_nums.begin(), unique_nums.end(), greater<int>());
        auto it = unique(unique_nums.begin(), unique_nums.end());
        if(it != unique_nums.end()){
            ans = 1;
        }
        unique_nums.erase(it, unique_nums.end());
        int n = unique_nums.size();
        for( int i = 0; i < n; ++i){
            long long x = unique_nums[i];
            if( x * unique_nums[0] <= ans){
                break;
            }
            for( int j = 0; j < i; ++j){
                long long y = unique_nums[j];
                if ( x * y <= ans){
                    break;
                }
                long long g = gcd(x, y);
                long long strength = (x*y)/(g*g);
                if(strength > ans){
                    ans = strength;
                }
            }
        }
        return ans;
    }
};