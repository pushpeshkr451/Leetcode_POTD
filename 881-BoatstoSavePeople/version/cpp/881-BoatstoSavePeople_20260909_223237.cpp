// Last updated: 09/09/2026, 22:32:37
1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        // unordered_map<int, int> mp;
5        int n = people.size();
6
7        // for (auto it : people)
8        //     mp[it]++;
9
10        sort(people.begin(), people.end());
11        int ans = 0;
12        int i = 0, j = n - 1;
13
14        while (i <= j) {
15            if (people[i] + people[j] <= limit) {
16                ans++;
17                i++;
18                j--;
19            } else if (people[j] + people[i] > limit) {
20                ans++;
21                j--;
22            } else {
23                i++;
24                ans++;
25            }
26        }
27
28        return ans;
29    }
30};