// Last updated: 09/06/2026, 19:42:32
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n),ans;

        pre[0]=LLONG_MIN;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i-1]);
        }

        suf[n-1]=LLONG_MIN;
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],nums[i+1]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]>pre[i]||nums[i]>suf[i]){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};