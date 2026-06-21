// Last updated: 21/06/2026, 08:02:40
1class Solution {
2public:
3    int maxDistance(string moves) {
4        int u=0,d=0,l=0,r=0,q=0;
5
6        for(char c:moves){
7            if(c=='U')u++;
8            else if(c=='D')d++;
9            else if(c=='L')l++;
10            else if(c=='R')r++;
11            else q++;
12        }
13        return abs(r-l)+abs(u-d)+q;
14    }
15};