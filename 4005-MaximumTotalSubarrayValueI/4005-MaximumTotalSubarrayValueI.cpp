// Last updated: 09/06/2026, 19:44:41
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int mi=*min_element(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());

        ans=(long long)k*(ma-mi);
        return ans;
    }
};