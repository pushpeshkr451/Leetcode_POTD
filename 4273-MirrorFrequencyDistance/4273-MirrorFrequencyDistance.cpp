// Last updated: 09/06/2026, 19:42:51
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int>f(256,0);

        for(auto c:s)f[c]++;
        int ans=0;

        for(char c='a';c<='z';c++){
            char m='a'+('z'-c);
            if(c<=m)ans+=abs(f[c]-f[m]);
        }

        for(char c='0';c<='9';c++){
            char m='0'+('9'-c);
            if(c<=m)ans+=abs(f[c]-f[m]);
        }

        return ans;
    }
};