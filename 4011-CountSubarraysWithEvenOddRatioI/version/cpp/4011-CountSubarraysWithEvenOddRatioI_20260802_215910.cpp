// Last updated: 02/08/2026, 21:59:10
1class Solution {
2public:
3    int countRatioSubarrays(vector<int>& nums, int a, int b) {
4        int n=nums.size();
5        int ans=0;
6
7        for(int i=0;i<n;i++){
8            int x=0,y=0;
9            // if(nums[i]%2)y++;
10            // else x++;
11            for(int j=i;j<n;j++){
12                if(nums[j]%2)y++;
13                else x++;
14                if(y>0 && x*b<=y*a)ans++;
15            }
16        }
17
18        return ans;
19    }
20};