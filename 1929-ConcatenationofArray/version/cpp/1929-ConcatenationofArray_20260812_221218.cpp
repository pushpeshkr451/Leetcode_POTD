// Last updated: 12/08/2026, 22:12:18
1class Solution {
2public:
3    int finalValueAfterOperations(vector<string>& operations) {
4        int ans=0;
5
6        for(auto it:operations){
7            if(it.find('+')!=string::npos)ans++;
8            else ans--;
9        }
10
11        return ans;
12    }
13};