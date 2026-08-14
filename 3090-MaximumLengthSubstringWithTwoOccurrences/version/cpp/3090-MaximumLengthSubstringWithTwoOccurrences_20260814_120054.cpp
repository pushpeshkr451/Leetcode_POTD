// Last updated: 14/08/2026, 12:00:54
1class Solution {
2public:
3    int maximumLengthSubstring(string s) {
4        unordered_map<char,int>mp;
5
6        int n=s.size();
7        int i=0,j=0;
8        int ans=INT_MIN;
9
10        while(j<n){
11            mp[s[j]]++;
12            if(mp[s[j]]>2){
13                while(mp[s[j]]>2){
14                    mp[s[i]]--;
15                    i++;
16                }
17            }
18            ans=max(ans,j-i+1);
19            j++;
20        }
21        
22        return ans;
23    }
24};