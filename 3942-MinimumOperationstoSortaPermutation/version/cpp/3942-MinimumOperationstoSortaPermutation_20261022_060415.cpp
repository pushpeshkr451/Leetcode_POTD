// Last updated: 22/10/2026, 06:04:15
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int n=nums.size();
5        int z=0;
6
7        for(int i=0;i<n;i++){
8            if(nums[i]==0){
9                z=i;
10                break;
11            }
12        }
13
14        bool inc=true,dec=true;
15
16        for(int i=0;i<n;i++){
17            if(nums[(z+i)%n]!=i)inc=false;
18            if(nums[(z+i)%n]!=(n-i)%n)dec=false;
19        }
20
21        if(!inc && !dec)return -1;
22
23        int ans=2e9;
24
25        if(inc){
26            int p=(n-z)%n;
27            if(p==0)ans=min(ans,0);
28            else ans=min(ans,min(n-p,p+2));
29        }
30
31        if(dec){
32            int p=n-1-z;
33            ans=min(ans,min(p+1,n-p+1));
34        }
35
36        return ans;
37    }
38};