// Last updated: 06/06/2026, 21:45:38
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n=nums.size();
5        if(!n){
6            return {0};
7        }
8        else {
9            vector<int>pre(n);
10            vector<int>suf(n);
11            pre[0]=nums[0];
12            suf[n-1]=nums[n-1];
13            for(int i=1;i<n;i++){
14                pre[i]=nums[i]+pre[i-1];
15            }
16            for(int j=n-2;j>=0;j--){
17                suf[j]=nums[j]+suf[j+1];
18            }
19            for(int i=0;i<n;i++){
20                nums[i]=abs(suf[i]-pre[i]);
21            }
22            return nums;
23        }
24    }
25};