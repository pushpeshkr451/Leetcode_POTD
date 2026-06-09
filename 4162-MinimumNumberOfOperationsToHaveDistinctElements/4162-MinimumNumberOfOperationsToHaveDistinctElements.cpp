// Last updated: 09/06/2026, 19:43:43
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }
        int i=0;

        int cnt=0;
        while(i<n){
            if(n-i==mp.size())break;
            cnt++;
            for(int j=1;j<=3;j++){
                if(i>=n)break;
                else{
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)mp.erase(nums[i]);
                    i++;
                }
            }
        }

        return cnt;
    }
};