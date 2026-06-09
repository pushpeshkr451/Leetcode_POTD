// Last updated: 09/06/2026, 19:44:17
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;

        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int>v;
        for(auto it:nums){
            v.push_back(abs(it-0));
        }

        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<j){
            ans+=(v[j]*v[j]);
            ans-=(v[i]*v[i]);
            i++;
            j--;
        }

        if(i==j){
            ans+=(v[i]*v[i]);
        }

        return ans;
    }
};