// Last updated: 09/06/2026, 19:42:12
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;

        // ans.push_back(nums[0]);
        int num=-1;

        int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=num){
                num=nums[i];
                cnt=1;
            }else cnt++;

            if(cnt<=k)ans.push_back(nums[i]);
        }

        return ans;
    }
};