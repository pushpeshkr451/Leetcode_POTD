// Last updated: 06/11/2026, 12:35:41
1class Solution {
2public:
3    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
4        int s = queries.size();
5        vector<int> arr(s);
6        sort(logs.begin(),logs.end(),[](auto &a,auto &b){return a[1]<b[1];});
7        int m = logs.size();
8        vector<pair<int,int>> sq;
9        for(int i = 0; i < s; i++){
10            sq.push_back({queries[i],i});
11        }
12        sort(sq.begin(),sq.end());
13        int l = 0;
14        int r = 0;
15        int active = 0;
16        vector<int> freq(n+1,0);
17        for(auto [en, idx] : sq){
18            int st = en-x;
19            while(r<m && logs[r][1] <= en){
20                int id = logs[r][0];
21                if(freq[id] == 0){
22                    active++;
23                }
24                freq[id]++;
25                r++;
26            }
27            while(l<r && logs[l][1]<st){
28                int id = logs[l][0];
29                freq[id]--;
30                if(freq[id] == 0){
31                    active--;
32                }
33                l++;
34            }
35            arr[idx] = n-active;
36        }
37        return arr;
38
39    }
40};