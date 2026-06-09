// Last updated: 09/06/2026, 19:42:15
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(auto it:nums){
            if(it==0)cnt++;
        }

        int nzero=n-cnt;
        int ans=0;

        for(int i=0;i<nzero;i++){
            if(nums[i]==0)ans++;
        }

        return ans;
        
    }
};