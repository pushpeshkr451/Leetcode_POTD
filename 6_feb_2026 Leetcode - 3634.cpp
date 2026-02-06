class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2)return 0;
        sort(nums.begin(),nums.end());
        int best=1,r=0;
        for(int l=0;l<n;l++){
            if(r<l)r=l;
            while(r+1<n && (long long)nums[r+1]<=(long long)nums[l]*k){
                r++;
            }
            best=max(best,r-l+1);
        }
        return n-best;
    }
};
