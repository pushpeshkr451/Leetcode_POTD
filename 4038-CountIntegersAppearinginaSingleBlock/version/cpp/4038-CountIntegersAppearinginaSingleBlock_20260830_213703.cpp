// Last updated: 30/08/2026, 21:37:03
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5
6        int n = nums.size();
7
8        for (int i = 0; i < n; i++) {
9            mp[nums[i]].push_back(i);
10        }
11
12        int ans = 0;
13
14        for (auto it : mp) {
15            if (it.second.size() == 1)
16                ans++;
17            else {
18                int val = it.second[0];
19
20                bool flag = false;
21
22                for (int i = 1; i < it.second.size(); i++) {
23                    if (it.second[i] - val == 1) {
24                        val = it.second[i];
25                        continue;
26                    } else {
27                        flag = true;
28                        break;
29                    }
30                }
31                if (!flag)
32                    ans++;
33            }
34        }
35
36        return ans;
37    }
38};