// Last updated: 19/07/2026, 22:26:37
1class Solution {
2public:
3    int maxPower(string s) {
4        unordered_map<char,int>mp;
5        int n=s.size();
6
7        int ans=1;
8        int i=0,j=0;
9        while(j<n){
10            mp[s[j]]++;
11            if(mp.size()==1)ans=max(ans,j-i+1);
12            else{
13                while(mp.size()!=1){
14                    mp[s[i]]--;
15                    if(mp[s[i]]==0)mp.erase(s[i]);
16                    i++;
17                }
18            }
19            j++;
20        }
21        if(mp.size()==1)ans=max(ans,j-i);
22        return ans;
23    }
24};