// Last updated: 31/05/2026, 08:23:28
1class Solution {
2public:
3    vector<int> maximumMEX(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>suf(n);
6        vector<bool>has(n+2,false);
7        int mex=0;
8
9        for(int i=n-1;i>=0;i--){
10            if(nums[i]<n+2)has[nums[i]]=true;
11
12            while(has[mex])mex++;
13            suf[i]=mex;
14        }
15
16        vector<int>res;
17        vector<int>seen(n+2,0);
18        int step=1;
19
20        for(int i=0;i<n;){
21            int target=suf[i];
22            if(target==0){
23                res.push_back(0);
24                i++;
25            }
26            else{
27                int cnt=0;
28                int j=i;
29                while(j<n){
30                    int val=nums[j];
31                    if(val<target && seen[val]!=step){
32                        seen[val]=step;
33                        cnt++;
34                    }
35                    if(cnt==target)break;
36                    j++;
37                }
38                res.push_back(target);
39                i=j+1;
40                step++;
41            }
42        }
43
44        return res;
45    }
46};