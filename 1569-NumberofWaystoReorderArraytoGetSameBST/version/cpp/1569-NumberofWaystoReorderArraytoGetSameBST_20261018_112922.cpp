// Last updated: 18/10/2026, 11:29:22
1class Solution {
2public:
3    vector<vector<long long>>ncr;
4    long long mod=1e9+7;
5    long long ways(vector<int>&v,int n){
6        if(n<=2)return 1;
7        vector<int>left,right;
8        for(int i=1;i<n;i++){
9            if(v[0]>v[i])left.push_back(v[i]);
10            else right.push_back(v[i]);
11        }
12        long long ans_left=ways(left,left.size());
13        long long ans_right=ways(right,right.size());
14
15        long long ans = (((ncr[n-1][left.size()]*ans_left)%mod)*ans_right)%mod;
16        return ans;
17    }
18    int numOfWays(vector<int>& v) {
19        int n=v.size();
20        ncr.resize(n + 1);
21         for(int i = 0; i < n + 1; ++i){
22        ncr[i] = vector<long long>(i + 1, 1);
23        for(int j = 1; j < i; ++j){
24            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
25            }
26            }
27            
28        return (ways(v,n)-1)%mod;
29    }
30};