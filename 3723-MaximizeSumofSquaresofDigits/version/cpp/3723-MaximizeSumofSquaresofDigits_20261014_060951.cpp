// Last updated: 14/10/2026, 06:09:51
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        if(9 * num < sum) return "";
5        string ans{};
6        int nines = sum / 9;
7        ans.append(nines, '9');
8        sum -= nines * 9;
9        if(sum) ans += (sum + '0');
10        ans.append(num - ans.size(), '0');
11        return ans;
12    }
13};