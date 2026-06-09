// Last updated: 09/06/2026, 19:42:54
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])ans+=(nums[i-1]-nums[i]);
        }

        return ans;
    }
};