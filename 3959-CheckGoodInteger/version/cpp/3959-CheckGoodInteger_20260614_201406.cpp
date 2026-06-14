// Last updated: 14/06/2026, 20:14:06
1class Solution {
2public:
3    int getLength(vector<int>& nums) {
4
5        int n=nums.size();
6        int ans=1;
7
8        for(int i=0;i<n;i++)
9        {
10            unordered_map<int,int> mp;
11            map<int,int> freq;
12
13            int dis=0;
14
15            for(int j=i;j<n;j++)
16            {
17                int x=nums[j];
18
19                int old=mp[x];
20
21                if(old==0)
22                {
23                    dis++;
24                }
25                else
26                {
27                    freq[old]--;
28
29                    if(freq[old]==0)
30                    {
31                        freq.erase(old);
32                    }
33                }
34
35                mp[x]++;
36                freq[old+1]++;
37
38                if(dis==1)
39                {
40                    ans=max(ans,j-i+1);
41                }
42                else if(freq.size()==2)
43                {
44                    auto it=freq.begin();
45
46                    int f1=it->first;
47                    it++;
48
49                    int f2=it->first;
50
51                    if(f2==2*f1)
52                    {
53                        ans=max(ans,j-i+1);
54                    }
55                }
56            }
57        }
58
59        return ans;
60    }
61};