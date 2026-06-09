// Last updated: 09/06/2026, 19:44:30
class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0;
        while(n>0){
            int p=n%10;
            if(p!=0){
                ans=ans*10+p;
            }
            n/=10;
        }
        string s=to_string(ans);

        reverse(s.begin(),s.end());
        return stoll(s);
    }
};