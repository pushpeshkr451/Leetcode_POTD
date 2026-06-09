// Last updated: 09/06/2026, 19:42:26
class Solution {
public:
    bool isprime(int n) {
        if(n<2)return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int ans=0;

        string s=to_string(n);
        reverse(s.begin(),s.end());
        int rev=stoi(s);

        int a=min(n,rev);
        int b=max(n,rev);
        for(int i=a;i<=b;i++){
            if(isprime(i))ans+=i;
        }

        return ans;
    }
};