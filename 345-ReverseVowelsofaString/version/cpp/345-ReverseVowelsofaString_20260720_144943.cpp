// Last updated: 20/07/2026, 14:49:43
1class Solution {
2public:
3    bool isVowel(char c) {
4        c = tolower(c);
5        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
6    }
7    string reverseVowels(string s) {
8        int n = s.size();
9        int i = 0, j = n - 1;
10
11        while(i<=j){
12            if(isVowel(s[i])&&isVowel(s[j])){
13                swap(s[i],s[j]);
14                i++;
15                j--;
16            }
17
18            else if(isVowel(s[i])&&!isVowel(s[j])){
19                j--;
20            }
21            else if(!isVowel(s[i])&&isVowel(s[j])){
22                i++;
23            }
24            else{
25                i++;
26                j--;
27            }
28        }
29
30        return s;
31    }
32};