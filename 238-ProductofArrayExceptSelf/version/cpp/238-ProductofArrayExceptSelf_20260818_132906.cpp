// Last updated: 18/08/2026, 13:29:06
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5
6        vector<int>pref(n),suff(n);
7
8        pref[0]=nums[0];
9        suff[n-1]=nums[n-1];
10
11        for(int i=1;i<n;i++){
12            pref[i]=pref[i-1]*nums[i];
13        }
14
15        for(int i=n-2;i>=0;i--){
16            suff[i]=suff[i+1]*nums[i];
17        }
18
19        vector<int>ans(n);
20
21        for(int i=0;i<n;i++){
22            if(i==0){
23                ans[i]=suff[i+1];
24            }
25            else if(i==n-1){
26                ans[i]=pref[i-1];
27            }
28            else{
29                ans[i]=pref[i-1]*suff[i+1];
30            }
31        }
32
33        return ans;
34    }
35};