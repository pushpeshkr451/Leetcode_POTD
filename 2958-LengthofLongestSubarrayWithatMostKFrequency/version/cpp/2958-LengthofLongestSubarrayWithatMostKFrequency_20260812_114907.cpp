// Last updated: 12/08/2026, 11:49:07
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& v, int k) {
4        int n=v.size();
5        map<int,int>m;
6        int i=0,j=0;
7        int ans=1;
8        while(i<n && j<n)
9        {
10            m[v[j]]++;
11            while(m[v[j]]>k)
12            {
13                m[v[i]]--;
14                i++;
15            }
16            ans=max(ans,j-i+1);
17            j++;
18        }
19        return ans;
20    }
21};