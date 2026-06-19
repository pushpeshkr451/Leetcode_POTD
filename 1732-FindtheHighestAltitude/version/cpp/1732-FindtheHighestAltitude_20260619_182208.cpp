// Last updated: 19/06/2026, 18:22:08
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int n=gain.size();
5        int ma=0;
6        int sum=0;
7
8        for(int i=0;i<n;i++){
9            sum+=gain[i];
10            ma=max(ma,sum);
11        }
12
13        return ma;
14    }
15};