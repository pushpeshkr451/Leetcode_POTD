// Last updated: 09/06/2026, 19:43:28
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans="";

        for(int i=0;i<n;i++){
            string s=words[i];
            int cnt=0;
            for(auto it:s){
                int a=it-'a';
                cnt+=weights[a];
            }
            int val=cnt%26;
            char res='z'-val;

            ans+=res;
        }
        return ans;
    }
};