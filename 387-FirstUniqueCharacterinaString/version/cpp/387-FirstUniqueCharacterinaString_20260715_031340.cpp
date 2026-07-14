// Last updated: 15/07/2026, 03:13:40
1class Solution {
2public:
3    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
4        int ans=0;
5        for(int i=0;i<hours.size();i++){
6            if(hours[i]>=target)ans++;
7        }
8        return ans;
9    }
10};