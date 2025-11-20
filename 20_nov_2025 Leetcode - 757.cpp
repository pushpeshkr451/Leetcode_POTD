class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 2;

        // sort intervals properly: end ascending, start descending
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y) {
            if (x[1] == y[1]) return x[0] > y[0];
            return x[1] < y[1];
        });

        vector<int> a, b;
        for (auto &it : intervals) {
            a.push_back(it[0]);
            b.push_back(it[1]);
        }

        // last two chosen points
        int x = b[0] - 1;
        int y = b[0];
        int ans = 2;

        for (int i = 1; i < intervals.size(); i++) {
            // case 1: interval already contains both
            if (a[i] <= x && y <= b[i]) continue;

            // case 2: interval contains only y
            if (a[i] <= y && y <= b[i]) {
                ans++;
                x = y;
                y = b[i];
            }
            // case 3: contains none
            else {
                ans += 2;
                x = b[i] - 1;
                y = b[i];
            }
        }
        return ans;
    }
};
