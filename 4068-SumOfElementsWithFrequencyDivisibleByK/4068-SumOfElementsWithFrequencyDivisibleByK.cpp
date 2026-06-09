// Last updated: 09/06/2026, 19:44:23
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        int ans=0;

        for(auto it:mp){
            if(it.second%k==0){
                ans+=(it.first)*it.second;
            }
        }

        return ans;
    }
};