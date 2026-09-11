// Last updated: 11/09/2026, 22:56:55
1class Solution {
2public:
3    int bagOfTokensScore(vector<int>& tokens, int power) {
4        int n=tokens.size();
5        int cnt=0;
6        int ans=0;
7
8        sort(tokens.begin(),tokens.end());
9
10        int i=0,j=n-1;
11
12        while(i<=j){
13            if(power>=tokens[i]){
14                cnt++;
15                power-=tokens[i];
16                i++;
17                ans=max(ans,cnt);
18            }
19            else if(cnt>0){
20                power+=tokens[j];
21                cnt--;
22                j--;
23                ans=max(ans,cnt);
24            }
25            else break;
26        }
27
28        return ans;
29    }
30};