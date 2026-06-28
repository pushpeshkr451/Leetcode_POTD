// Last updated: 28/06/2026, 08:08:24
1class Solution {
2public:
3    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int st, int en) {
4        if(arr.empty())return {};
5
6        sort(arr.begin(),arr.end());
7        vector<vector<int>>merge;
8        merge.push_back(arr[0]);
9
10        for(int i=1;i<arr.size();i++){
11            if(arr[i][0]<=merge.back()[1]+1)merge.back()[1]=max(merge.back()[1],arr[i][1]);
12            else merge.push_back(arr[i]);
13        }
14
15        vector<vector<int>>ans;
16
17        for(auto x:merge){
18            int l=x[0];
19            int r=x[1];
20
21            if(r<st || l>en)ans.push_back(x);
22            else if(l>=st && r<=en)continue;
23            else if(l<st && r>en){
24                ans.push_back({l,st-1});
25                ans.push_back({en+1,r});
26            }
27            else if(l<st)ans.push_back({l,st-1});
28            else ans.push_back({en+1,r});
29        }
30
31        return ans;
32    }
33};