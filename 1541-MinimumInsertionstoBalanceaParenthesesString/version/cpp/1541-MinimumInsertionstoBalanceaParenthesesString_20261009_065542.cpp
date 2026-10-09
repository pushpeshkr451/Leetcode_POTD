// Last updated: 09/10/2026, 06:55:42
1class Solution {
2public:
3    int minInsertions(string s) {
4        stack<char> v;
5        int ans = 0;
6        for(int i = 0;i < s.size();i++){
7            if(s[i] == '(') v.push(s[i]);
8            else{
9                if(s[i] == ')' && i < s.size() && s[i + 1] == ')') {
10                    if(!v.empty())
11                        v.pop();
12                    else ans++;
13                    i++;       // because we considered i+1 in this case
14                }
15                else if(s[i] == ')' && i < s.size() && s[i + 1] != ')'){
16                    if(!v.empty()){
17                        v.pop();
18                        ans++;
19                    }
20                    else ans += 2;
21                }
22            }
23        }
24        if(v.empty()) return ans;
25        return v.size()*2 + ans;
26    }
27};