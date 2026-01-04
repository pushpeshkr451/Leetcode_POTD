class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int cnt=0;
            int sum=0;
            for(int j=1;j<=nums[i];j++){
                if(cnt>4)break;
                if(nums[i]%j==0){
                    cnt++;
                    sum+=j;
                }
            }
            if(cnt==4)ans+=sum;
        }
        return ans;
    }
};
