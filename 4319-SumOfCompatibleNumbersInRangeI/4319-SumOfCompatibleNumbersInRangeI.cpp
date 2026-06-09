// Last updated: 09/06/2026, 19:42:10
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;

        for(int i=1;i<=n+k;i++){
            if(abs(i-n)<=k && (n&i)==0)ans+=i;
        }

        return ans;
    }
};