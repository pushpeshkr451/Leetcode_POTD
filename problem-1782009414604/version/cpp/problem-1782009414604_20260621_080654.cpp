// Last updated: 21/06/2026, 08:06:54
1class Solution {
2public:
3    int countValidSubarrays(vector<int>& nums, int x) {
4        int n=nums.size();
5        int ans=0;
6
7        for(int i=0;i<n;i++){
8            long long sum=0;
9            for(int j=i;j<n;j++){
10                sum+=nums[j];
11
12                if(sum%10==x){
13                    long long cur=sum;
14                    while(cur>=10){
15                        cur/=10;
16                    }
17
18                    if(cur==x)ans++;
19                }
20            }
21        }
22        return ans;
23    }
24};