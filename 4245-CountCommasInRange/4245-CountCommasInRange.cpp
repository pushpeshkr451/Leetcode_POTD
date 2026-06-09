// Last updated: 09/06/2026, 19:43:16
class Solution {
public:
    int countCommas(int n) {
        int ans=0;

        for(int i=1;i<=n;i++){
            int digit=log10(i)+1;

            ans+=(digit-1)/3;
        }

        return ans;
    }
};