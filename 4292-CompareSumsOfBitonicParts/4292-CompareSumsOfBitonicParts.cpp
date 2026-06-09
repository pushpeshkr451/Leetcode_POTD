// Last updated: 09/06/2026, 19:42:29
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());

        int i=0,n=nums.size();
        long long sum1=0;
        for(i;i<n;i++){
            sum1+=nums[i];
            if(nums[i]==maxi)break;
        }

        for(i;i<n;i++){
            sum1-=nums[i];
        }

        if(sum1==0)return -1;
        if(sum1>0)return 0;
        return 1;
    }
};