// Last updated: 09/06/2026, 19:43:35
class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z') {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v++;
            else
                c++;
        }
            
        }
        if(c>0) return v/c;

        return 0;
    }
};