// Last updated: 21/07/2026, 22:30:33
1class Solution {
2public:
3    string removeDuplicates(string s) {
4        stack<char>st;
5
6        for(int i=0;i<s.size();i++){
7            if(st.size()>0 && st.top()==s[i]){
8                st.pop();
9            }
10            else{
11                st.push(s[i]);
12            }
13        }
14
15        string ans="";
16
17        while(st.size()>0){
18            char ch=st.top();
19            ans+=ch;
20            st.pop();
21        }
22        reverse(ans.begin(),ans.end());
23
24        return ans;
25    }
26};