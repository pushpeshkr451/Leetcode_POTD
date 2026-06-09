// Last updated: 09/06/2026, 19:43:37
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        vector<int>suf(n);
        vector<bool>has(n+2,false);
        int mex=0;

        for(int i=n-1;i>=0;i--){
            if(nums[i]<n+2)has[nums[i]]=true;

            while(has[mex])mex++;
            suf[i]=mex;
        }

        vector<int>res;
        vector<int>seen(n+2,0);
        int step=1;

        for(int i=0;i<n;){
            int target=suf[i];
            if(target==0){
                res.push_back(0);
                i++;
            }
            else{
                int cnt=0;
                int j=i;
                while(j<n){
                    int val=nums[j];
                    if(val<target && seen[val]!=step){
                        seen[val]=step;
                        cnt++;
                    }
                    if(cnt==target)break;
                    j++;
                }
                res.push_back(target);
                i=j+1;
                step++;
            }
        }

        return res;
    }
};