// Last updated: 09/06/2026, 19:45:24
class Solution {
public:
    int solve(vector<int>&nums,int p){
        int n=nums.size();
        int ans=0,curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==p){
                ans+=abs(i-curr);
                curr+=2;
            }
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd,even;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)even.push_back(i);
            else odd.push_back(i);
        }
        int a=even.size(),b=odd.size();

        if(abs(a-b)>1)return -1;

        if(a>b)return solve(nums,0);
        else if(b>a)return solve(nums,1);
        else return min(solve(nums,0),solve(nums,1));
        
    }
};