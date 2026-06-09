// Last updated: 09/06/2026, 19:43:06
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==1){
                    if(nums[j]==2)ans=min(ans,abs(i-j));
                }
                else if(nums[i]==2){
                    if(nums[j]==1)ans=min(ans,abs(i-j));
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};