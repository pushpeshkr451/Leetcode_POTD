// Last updated: 09/06/2026, 19:42:20
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) {
            return r - l + 1;
        }

        int ans=0;
        int maxi=pow(r,1.0/k)+1;

        for(int i=0;i<=maxi;i++){
            long long num=pow(i,k);
            if(num<=r && num>=l)ans++;
        }

        return ans;
    }
};