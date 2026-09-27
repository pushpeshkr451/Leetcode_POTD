// Last updated: 27/09/2026, 06:02:44
1class Solution {
2public:
3    string reverseParentheses(string s) 
4    {
5        stack<char> st;
6        string s1;
7        for(const char& ch : s)
8        {
9            if(ch=='(')
10            {
11                st.push(ch);
12            }
13            else if(ch==')')
14            {
15                s1="";
16               while(st.top()!='(')
17               {
18                s1.push_back(st.top());
19                st.pop();
20               }
21               st.pop();
22               for(int i=0; i<s1.length(); i++)
23               {
24                  st.push(s1[i]);
25               }
26            }
27            else
28            st.push(ch);
29        }
30        string result;
31        while (!st.empty()) 
32        {
33            result.push_back(st.top());
34            st.pop();
35        }
36        reverse(result.begin(),result.end());
37        return result;
38    }
39};