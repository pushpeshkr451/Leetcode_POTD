// Last updated: 01/10/2026, 07:46:40
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5    for (char c : s) {
6        if (c == '(' || c == '{' || c == '[') {
7            st.push(c);
8        } else {
9            if (st.empty()) return false;
10            if ((c == ')' && st.top() != '(') ||
11                (c == '}' && st.top() != '{') ||
12                (c == ']' && st.top() != '[')) {
13                return false;
14            }
15            st.pop();
16        }
17    }
18    return st.size()==0;
19    }
20};