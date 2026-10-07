// Last updated: 07/10/2026, 11:03:16
1class Solution {
2public:
3    bool isValid(string& s){
4    int cnt = 0;
5    for(char c : s){
6        if(c == '('){
7            cnt++;
8        }else if(c == ')'){
9            cnt--;
10            if(cnt < 0){
11                return false;
12            }
13        }
14    }
15    return cnt == 0;
16}
17    void func(vector<string>& ans, string s, int removed, int& mn, unordered_set<string>& seen){
18        if(removed > mn){
19            return;
20        }
21        if(seen.count(s)){
22            return;
23        }
24        seen.insert(s);
25        if(isValid(s)){
26            if(removed < mn){
27                ans.clear();
28                mn = removed;
29            }
30            if(removed == mn){
31                ans.push_back(s);
32            }
33            return;
34        }
35        for(int i = 0; i < s.length(); ++i){
36            if(s[i] == '(' || s[i] == ')'){
37                string temp = s;
38                temp.erase(temp.begin() + i);
39                func(ans, temp, removed + 1, mn, seen);
40            }
41        }
42    }
43    vector<string> removeInvalidParentheses(string s) {
44        vector<string> ans;
45        unordered_set<string> seen;
46        int mn = INT_MAX;
47        func(ans, s, 0, mn, seen);
48        return ans;
49    }
50};