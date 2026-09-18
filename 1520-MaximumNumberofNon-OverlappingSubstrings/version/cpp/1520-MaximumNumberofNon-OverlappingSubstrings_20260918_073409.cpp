// Last updated: 18/09/2026, 07:34:09
1class Solution {
2public:
3    vector<string> maxNumOfSubstrings(string s) {
4        map<char, vector<int>> mp;
5        for(int i=0;i<s.size();i++) {
6            if(mp.find(s[i]) == mp.end()) {
7                mp[s[i]] = {i, i+1};
8            } else {
9                mp[s[i]][1] = i+1;
10            }
11        }
12
13        for(int m=0;m<2;m++) {
14            for(auto it:mp) {
15                int start = mp[it.first][0];
16                int end = mp[it.first][1];
17                for(int i=it.second[0]; i<it.second[1];i++) {
18                    start = min(mp[s[i]][0], start);
19                    end = max(mp[s[i]][1], end);
20                }
21                mp[it.first][0] = start;
22                mp[it.first][1] = end;
23            }
24        }
25        vector<vector<int>> vec;
26        for(auto it:mp) {
27            vec.push_back({it.second[1], it.second[0], it.first-'a'});
28        }
29        sort(vec.rbegin(), vec.rend());
30
31        int cnt = 0;
32        vector<pair<int, int>> ans;
33        if (vec.size()>=1) {
34            ans.push_back({vec[0][0], vec[0][1]});
35        }
36
37        for(int i=1;i<vec.size();i++) {
38            // cout<<"i - "<<i<<" "<<vec[i][0]<<" "<<vec[i][1]<<"\n";
39            auto cur = vec[i];
40            auto prev = ans[ans.size()-1];
41
42            if(cur[0]<=prev.second) {
43                ans.push_back({cur[0], cur[1]});
44            } else if(cur[1]>=prev.second) {
45                ans.pop_back();
46                ans.push_back({cur[0], cur[1]});
47            }
48        }
49
50        vector<string> fans;
51        for(int i=0;i<ans.size();i++) {
52            fans.push_back(s.substr(ans[i].second, ans[i].first-ans[i].second));
53        }
54        return fans;
55    }
56};