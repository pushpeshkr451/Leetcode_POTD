// Last updated: 13/07/2026, 20:14:58
1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int> ans;
5
6        string s = "123456789";
7        string l = to_string(low);
8        string h = to_string(high);
9
10        for(int i = l.size(); i <= h.size(); i++) {
11            for(int j = 0; j <= 9 - i; j++) {
12                string n = s.substr(j, i);
13                int num = stoi(n);
14                if(num >= low && num <= high)
15                    ans.push_back(num);
16            }
17        }
18
19        return ans;
20    }
21};