// Last updated: 20/06/2026, 20:09:47
1class Solution {
2public:
3    int minLights(vector<int>& lights) {
4        int n=lights.size();
5        vector<int>diff(n+1,0);
6
7        for(int i=0;i<n;i++){
8            if(lights[i]>0){
9                int l=max(0,i-lights[i]);
10                int r=min(n-1,i+lights[i]);
11
12                diff[l]++;
13                diff[r+1]--;
14            }
15        }
16        vector<int>cover(n,0);
17
18        int cur=0;
19
20        for(int i=0;i<n;i++){
21            cur+=diff[i];
22            cover[i]=cur;
23        }
24
25        int ans=0;
26
27        for(int i=0;i<n;i++){
28            if(cover[i]==0){
29                ans++;
30                i+=2;
31            }
32        }
33
34        return ans;
35    }
36};