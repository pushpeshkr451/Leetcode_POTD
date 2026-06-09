// Last updated: 09/06/2026, 19:42:22
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        long long sum=0;

        for(auto x:nums){
            int mn=x;
            for(int d=1;d*d<=x;d++){
                if(x%d==0){
                    if(st.count(d)){
                        mn=min(mn,d);
                    }
                    int other=x/d;

                    if(st.count(other))mn=min(mn,other);
                }
            }
            sum+=mn;
        }

        return sum;
    }
};