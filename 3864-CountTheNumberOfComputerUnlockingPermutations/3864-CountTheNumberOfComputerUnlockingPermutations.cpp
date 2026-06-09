// Last updated: 09/06/2026, 19:45:46
class Solution {
public:
// By the way we can solve it in very easy way 
// in this question the intution is simple we have to unlock all the computer 
//  using the computer 0 which has less complexity than the computer 0 is anyone has greater complexity than the computer 0 then simply return 0 else there are ans is the factorial of n-1! so simply multiply with it and take the modulo 1e9+7
    int countPermutations(vector<int>& comp) {
        int n=comp.size();
        long long ans=1;
        for(int i=1;i<n;i++){
            if(comp[i]<=comp[0])return 0;
            ans*=i;
            ans%=(int)1e9+7;
        }
        return ans;
    }
};