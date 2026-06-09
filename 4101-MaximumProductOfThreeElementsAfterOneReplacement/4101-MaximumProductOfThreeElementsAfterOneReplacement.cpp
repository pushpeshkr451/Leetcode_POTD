// Last updated: 09/06/2026, 19:44:08
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans=1e5;
        vector<int>v;

        for(auto it:nums){
            v.push_back(abs(it-0));
        }

        sort(v.begin(),v.end());

        int n=v.size();

        ans*=v[n-1];
        ans*=v[n-2];

        return ans;
    }
};