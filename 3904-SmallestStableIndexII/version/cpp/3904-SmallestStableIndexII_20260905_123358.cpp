// Last updated: 05/09/2026, 12:33:58
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n=nums.size();
5
6        vector<int>pre(n),suf(n);
7
8        pre[0]=nums[0];
9        for(int i=1;i<n;i++){
10            pre[i]=max(pre[i-1],nums[i]);
11        }
12
13        suf[n-1]=nums[n-1];
14        for(int i=n-2;i>=0;i--){
15            suf[i]=min(suf[i+1],nums[i]);
16        }
17
18        for(int i=0;i<n;i++){
19            if(pre[i]-suf[i]<=k)return i;
20        }
21
22        return -1;
23    }
24};