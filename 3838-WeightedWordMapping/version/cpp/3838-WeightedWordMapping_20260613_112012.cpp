// Last updated: 13/06/2026, 11:20:12
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        int n=words.size();
5        string ans="";
6
7        for(int i=0;i<n;i++){
8            string s=words[i];
9            int cnt=0;
10            for(auto it:s){
11                int a=it-'a';
12                cnt+=weights[a];
13            }
14            int val=cnt%26;
15            char res='z'-val;
16
17            ans+=res;
18        }
19        return ans;
20    }
21};