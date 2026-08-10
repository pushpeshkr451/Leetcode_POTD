// Last updated: 10/08/2026, 21:42:36
1class Solution {
2public:
3    double minPrice(vector<int>& prices, vector<int>& discounts) {
4        int n = prices.size();
5        int m = discounts.size();
6
7        sort(prices.begin(), prices.end());
8        sort(discounts.begin(), discounts.end());
9
10        int i = n - 1, j = m - 1;
11
12        double ans = 0;
13        while (i >= 0) {
14            if (j < 0) {
15                ans += prices[i];
16            } else{
17                ans += (prices[i] * (100 - discounts[j])) / 100.0;
18                cout<<ans<<endl;
19            }
20            i--;
21            j--;
22        }
23
24        return ans;
25    }
26};