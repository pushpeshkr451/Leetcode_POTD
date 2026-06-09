// Last updated: 09/06/2026, 19:42:30
class Solution {
public:
    void dfs(int i,int n,int k,int cost,string &s,vector<string>&ans){
        if(cost>k)return ;

        if(i==n){
            ans.push_back(s);
            return;
        }

        s.push_back('0');
        dfs(i+1,n,k,cost,s,ans);
        s.pop_back();

        if(i==0 || s.back()!='1'){
            s.push_back('1');
            dfs(i+1,n,k,cost+i,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;

        string s="";

        dfs(0,n,k,0,s,ans);
        return ans;
    }
};