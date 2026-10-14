// Last updated: 14/10/2026, 06:09:16
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        if (9 * num < sum)
5            return "";
6        string ans{};
7        int nines = sum / 9;
8        ans.append(nines, '9');
9        sum -= nines * 9;
10        if (sum)
11            ans += (sum + '0');
12        ans.append(num - ans.size(), '0');
13        return ans;
14    }
15};