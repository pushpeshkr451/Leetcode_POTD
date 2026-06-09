// Last updated: 09/06/2026, 19:43:32
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mp;
        for(auto it:bulbs){
            mp[it]++;
        }

        vector<int>ans;

        for(auto it:mp){
            if(it.second%2==1)ans.push_back(it.first);
        }

        return ans;
    }
};