// Last updated: 09/06/2026, 19:43:14
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();

        int cnt=INT_MAX,ans=-1;

        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize){
                if(cnt>capacity[i]){
                    cnt=capacity[i];
                    ans=i;
                }
            }
        }

        return ans;
    }
};