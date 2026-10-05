// Last updated: 05/10/2026, 07:56:52
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4        stack<int> st;
5        int score = 0;
6        for(int i = 0; i < s.size(); i++){
7            if(s[i] == '('){
8                st.push(score);
9                score = 0;
10            }
11            else {
12                score = st.top() + max(2 * score, 1);
13                st.pop();
14            }
15        }
16        return score;
17    }
18};