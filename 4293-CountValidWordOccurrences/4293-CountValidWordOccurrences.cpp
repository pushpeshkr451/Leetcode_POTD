// Last updated: 09/06/2026, 19:42:27
class Solution {
public:
    bool solve(char c){
        return c>='a' && c<='z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";

        for(auto &x:chunks)s+=x;

        unordered_map<string,int>mp;

        int n=s.size();
        int i=0;

        while(i<n){
            if(!solve(s[i])){
                i++;
                continue;
            }

            string t="";

            while(i<n){
                if(solve(s[i])){
                    t+=s[i];
                }
                else if(s[i]=='-'){
                    if(i-1>=0 && i+1<n && solve(s[i-1]) && solve(s[i+1])){
                        t+=s[i];
                    }
                    else break;
                }
                else break;
                i++;
            }
            mp[t]++;
        }

        vector<int>ans;

        for(auto &q:queries){
            ans.push_back(mp[q]);
        }

        return ans;
    }
};