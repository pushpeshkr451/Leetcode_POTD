// Last updated: 22/07/2026, 00:26:20
1class Solution {
2public:
3    string reverseOnlyLetters(string s) {
4        string alph="";
5
6        for(auto it:s)if(isalpha(it))alph+=it;
7
8        reverse(alph.begin(),alph.end());
9        int j=0;
10        for(int i=0;i<s.size();i++){
11            if(isalpha(s[i])){
12                s[i]=alph[j];
13                j++;
14            }
15        }
16        return s;
17    }
18};