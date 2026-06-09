// Last updated: 09/06/2026, 19:43:07
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp,mp1,mp2;

        for(auto it:nums1){
            mp1[it]++;
            mp[it]++;
        }
        for(auto it:nums2){
            mp2[it]++;
            mp[it]++;
        }

        int ans=0,pans=0;
        
        for(auto it:mp){
            if(it.second%2!=0)return -1;
        }

        for(auto it:mp1){
            int x=it.first;
            if(mp1[x]>mp2[x])ans+=mp1[x]-mp2[x];
            // ans+=abs(mp1[x]-mp2[x]);
        }

        return ans/2;
    }
};