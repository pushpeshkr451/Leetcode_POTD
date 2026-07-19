// Last updated: 19/07/2026, 08:41:33
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n=s.size(), a=0, b=0;
        string ans;
        for(auto c : s){
            if(c==x) a++;
            else if(c==y) b++;
            else ans.push_back(c);
        }
        ans.append(b,y);
        ans.append(a,x);
        return ans;
    }
};