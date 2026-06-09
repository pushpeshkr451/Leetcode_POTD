// Last updated: 09/06/2026, 19:44:09
class Solution {
public:
    bool isprime(int n){
        if(n<2)return false;
        if(n==2)return true;

        if(n%2==0)return false;
        for(int i=3;1LL*i*i<=n;i+=2){
            if(n%i==0)return false;
        }
        return true;
    }
    
    bool completePrime(int num) {

        string s=to_string(num);
        int n=s.size();

        for(int len=1;len<=n;len++){
            int val=stoi(s.substr(0,len));
            if(!isprime(val))return false;
        }

        for(int len=1;len<=n;len++){
            int val=stoi(s.substr(n-len,len));
            if(!isprime(val))return false;
        }

        return true;
        
    }
};