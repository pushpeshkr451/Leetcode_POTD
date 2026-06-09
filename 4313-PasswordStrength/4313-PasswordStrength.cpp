// Last updated: 09/06/2026, 19:42:17
class Solution {
public:
    int passwordStrength(string password) {
        vector<int>lower(26,0),upper(26,0),digit(10,0);

        vector<int>special(4,0);
        int ans=0;

        for(char c:password){
            if(c>='a' && c<='z'){
                if(lower[c-'a']==0){
                    ans+=1;
                    lower[c-'a']=1;
                }
            }
            else if(c>='A' && c<='Z'){
                if(upper[c-'A']==0){
                    ans+=2;
                    upper[c-'A']=1;
                }
            }
            else if(c>='0' && c<='9'){
                if(digit[c-'0']==0){
                    ans+=3;
                    digit[c-'0']=1;
                }
            }
            else{
                int idx=0;
                if(c=='!')idx=0;
                else if(c=='@')idx=1;
                else if(c=='#')idx=2;
                else idx=3;

                if(special[idx]==0){
                    ans+=5;
                    special[idx]=1;
                }
            }
        }
        return ans;
    }
};