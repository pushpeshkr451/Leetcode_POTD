class Solution {
public:
    int solve(int i, char lastColor, int lastCost, string &a, vector<int> &v) {
        if (i == a.size()) return 0;

        if (a[i] == lastColor) {
            if (v[i] < lastCost) {
                return v[i] + solve(i + 1, lastColor, lastCost, a, v);
            } else {
                return lastCost + solve(i + 1, a[i], v[i], a, v);
            }
        }
        return solve(i + 1, a[i], v[i], a, v);
    }

    int minCost(string colors, vector<int>& neededTime) {
        return solve(1, colors[0], neededTime[0], colors, neededTime);
    }
};
