// Last updated: 09/06/2026, 19:43:33
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int z=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                z=i;
                break;
            }
        }

        bool inc=true,dec=true;

        for(int i=0;i<n;i++){
            if(nums[(z+i)%n]!=i)inc=false;
            if(nums[(z+i)%n]!=(n-i)%n)dec=false;
        }

        if(!inc && !dec)return -1;

        int ans=2e9;

        if(inc){
            int p=(n-z)%n;
            if(p==0)ans=min(ans,0);
            else ans=min(ans,min(n-p,p+2));
        }

        if(dec){
            int p=n-1-z;
            ans=min(ans,min(p+1,n-p+1));
        }

        return ans;
    }
};