// Last updated: 15/07/2026, 02:42:05
1class Solution {
2public:
3    bool checkIfPangram(string s) {
4        set<char>st(s.begin(),s.end());
5
6        return st.size()==26 ? 1:0;
7    }
8};