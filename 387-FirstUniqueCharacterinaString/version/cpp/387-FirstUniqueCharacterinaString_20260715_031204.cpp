// Last updated: 15/07/2026, 03:12:04
1class Solution {
2public:
3    string firstPalindrome(vector<string>& words) {
4        int n=words.size();
5
6        for(int i=0;i<n;i++){
7            string s=words[i];
8            reverse(s.begin(),s.end());
9            if(s==words[i])return s;
10        }
11        return "";
12    }
13};