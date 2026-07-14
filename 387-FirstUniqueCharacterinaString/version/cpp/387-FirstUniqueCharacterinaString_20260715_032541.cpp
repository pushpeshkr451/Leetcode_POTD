// Last updated: 15/07/2026, 03:25:41
1class Solution {
2public:
3    string toLowerCase(string s) {
4        string ans="";
5        for(auto it:s){
6            if(isupper(it)){
7                char ch=it-'A';
8                ans+=(ch+'a');
9            }
10            else ans+=it;
11        }
12        return ans;
13    }
14};