// Last updated: 09/06/2026, 19:45:23
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string>st;
        int n=s.size();
        int i=0;
        string a="";
        vector<string>ans;
        while(i<n){
            a+=s[i];
            if(st.count(a)){
                st.insert(a);

            }
            else{
                st.insert(a);
                ans.push_back(a);
                a="";
            }
            i++;
        }
        return ans;
    }
};