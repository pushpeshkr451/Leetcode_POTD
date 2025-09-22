class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>v(101,0);

        int maxi=INT_MIN;
        for(auto it:nums){
            v[it]++;
            maxi=max(maxi,v[it]);
        }
        int ans=0;
        for(auto it:v){
            if(it==maxi)ans+=it;
        }
        return ans;
    }
};
