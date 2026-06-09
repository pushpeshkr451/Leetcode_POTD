// Last updated: 09/06/2026, 19:43:23
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int cnt=1;
        int val1=0,val2=0;
        int n=nums.size();

        bool flag=true;

        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                flag=!flag;
            }
            if(cnt==6){
                flag=!flag;
                cnt=0;
            }
            if(flag)val1+=nums[i];
            else val2+=nums[i];
            cnt++;
        }

        return val1-val2;
    }
};