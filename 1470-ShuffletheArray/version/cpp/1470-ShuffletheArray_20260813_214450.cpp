// Last updated: 13/08/2026, 21:44:50
1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        vector<int>ans(2*n);
5        int i=0,x=0,y=1,j=n;
6        while(i<n){
7            ans[x]=nums[i];
8            x+=2;
9            i++;
10            ans[y]=nums[j];
11            y+=2;
12            j++;
13        }
14        return ans;
15    }
16};