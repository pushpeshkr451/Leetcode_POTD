// Last updated: 30/08/2026, 21:38:36
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        unordered_map<int, int> mp;
5
6        int n = nums.size();
7
8        mp[nums[0]] = 1;
9
10        for(int i = 1; i < n; i++){
11            if(nums[i] != nums[i - 1]){
12                mp[nums[i]]++;
13            }
14        }
15
16        int cnt = 0;
17
18        for(auto &p : mp){
19            if(p.second == 1){
20                cnt++;
21            }
22        }
23
24        return cnt;
25    }
26};