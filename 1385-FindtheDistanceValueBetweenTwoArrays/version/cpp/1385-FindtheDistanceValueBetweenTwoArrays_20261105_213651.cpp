// Last updated: 05/11/2026, 21:36:51
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int count{0};
5
6        for (int i = 0; i < arr1.size(); i++) {
7            bool skip = false;
8
9            for (int j = 0; j < arr2.size(); j++) {
10                if (abs(arr1[i] - arr2[j]) <= d) {
11                    skip = true;
12                    break;
13                }
14            }
15
16            if (skip == false)
17                count++;
18
19            if (skip)
20                continue;
21        }
22
23        return count;
24    }
25};