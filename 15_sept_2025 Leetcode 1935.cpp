class Solution {
public:
    int canBeTypedWords(string text, string brok) {
        set<char>st;

        for(auto it:brok){
            st.insert(it);
        }

        bool flag=false;
        int ans=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' ' && !flag){
                ans++;
            }
            else if(text[i]==' ' && flag){
                flag=!flag;
            }
            else if(st.count(text[i])){
                flag=true;
            }
        }
        if(!flag)ans++;
        return ans;
    }
};
