class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        set<int> st;
        for (auto it : friendships) {
            unordered_set<int> mp(languages[it[0] - 1].begin(),
                                  languages[it[0] - 1].end());
            bool flag = false;
            for (auto it1 : languages[it[1] - 1]) {
                if (mp.find(it1) != mp.end()) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                st.insert(it[0] - 1);
                st.insert(it[1] - 1);
            }
        }

        vector<int> cnt(n + 1, 0);
        for (auto person : st) {
            for (auto lang : languages[person]) {
                cnt[lang]++;
            }
        }

        int best = 0;
        for (int i = 1; i <= n; i++) {
            best = max(best, cnt[i]);
        }

        return st.size() - best;
    }
};
