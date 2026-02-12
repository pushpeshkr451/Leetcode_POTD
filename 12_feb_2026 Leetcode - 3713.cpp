class Solution {
public:
    bool check(vector<int>& v) {

        int same = -1;

        for (auto it : v) {
            if (it != 0 && same == -1) {
                same = it;
            } else if (it != 0 && same != -1) {
                if (it != same)
                    return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();

        int ans = 1;

        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                if (check(cnt)) {
                    ans = max(ans, j - i + 1);
                }
            }
            cnt[s[i] - 'a']--;
        }

        return ans;
    }
};
