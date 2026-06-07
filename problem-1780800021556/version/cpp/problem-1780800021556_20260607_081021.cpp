// Last updated: 07/06/2026, 08:10:21
1class Solution {
2public:
3    void dfs(int i,int n,int k,int cost,string &s,vector<string>&ans){
4        if(cost>k)return ;
5
6        if(i==n){
7            ans.push_back(s);
8            return;
9        }
10
11        s.push_back('0');
12        dfs(i+1,n,k,cost,s,ans);
13        s.pop_back();
14
15        if(i==0 || s.back()!='1'){
16            s.push_back('1');
17            dfs(i+1,n,k,cost+i,s,ans);
18            s.pop_back();
19        }
20    }
21    vector<string> generateValidStrings(int n, int k) {
22        vector<string>ans;
23
24        string s="";
25
26        dfs(0,n,k,0,s,ans);
27        return ans;
28    }
29};