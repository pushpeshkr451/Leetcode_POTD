// Last updated: 09/07/2026, 13:30:35
1class Solution {
2public:
3    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
4        vector<int>pre(n);
5        int a=0;
6        pre[0]=0;
7        for(int i=1;i<n;i++){
8            if(abs(nums[i]-nums[i-1])<=maxDiff){
9                pre[i]=a;
10            }
11            else{
12                a++;
13                pre[i]=a;
14            }
15        }
16        vector<bool>ans;
17        for(int i=0;i<queries.size();i++){
18            int x=queries[i][0];
19            int y=queries[i][1];
20            ans.push_back(pre[x]==pre[y]);
21        }
22        return ans;
23    }
24};