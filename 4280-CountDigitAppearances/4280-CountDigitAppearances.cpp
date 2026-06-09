// Last updated: 09/06/2026, 19:42:46
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(int a: nums){
            while(a>0){
                int dig=a%10;
                if(dig==digit) ans++;
                a=a/10;
            }
        }
        return ans;
    }
};