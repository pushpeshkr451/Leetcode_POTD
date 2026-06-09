// Last updated: 09/06/2026, 19:42:36
class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        if(s[0]-'0'==x)return false;
        
        for(int i=1;i<s.size();i++){
            if(s[i]-'0'==x)return true;
        }

        return false;
    }
};