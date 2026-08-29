// Last updated: 29/08/2026, 19:45:56
1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
4        int n = nums.size();
5
6        vector<int> sorted = nums;
7        sort(sorted.begin(), sorted.end());
8
9        unordered_map<int, vector<int>> group;
10        unordered_map<int, int> groupId;
11        unordered_map<int, int> pos;
12
13        int id = 1;
14        group[id].push_back(sorted[0]);
15        groupId[sorted[0]] = id;
16
17        for(int i = 1; i < n; i++){
18            if(sorted[i] - sorted[i - 1] > limit){
19                id++;
20            }
21
22            group[id].push_back(sorted[i]);
23            groupId[sorted[i]] = id;
24        }
25
26        // Rebuild nums using the smallest
27        // available value from its group
28        for(int i = 0; i < n; i++){
29            int grp = groupId[nums[i]];
30
31            nums[i] = group[grp][pos[grp]];
32            pos[grp]++;
33        }
34
35        return nums;
36    }
37};