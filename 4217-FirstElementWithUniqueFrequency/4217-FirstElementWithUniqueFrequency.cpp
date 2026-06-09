// Last updated: 09/06/2026, 19:43:26
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        unordered_map<int,int>freq;

        for(auto it:mp){
            freq[it.second]++;
        }

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(freq[mp[nums[i]]]==1)return nums[i];
        }
        return -1;
    }
};