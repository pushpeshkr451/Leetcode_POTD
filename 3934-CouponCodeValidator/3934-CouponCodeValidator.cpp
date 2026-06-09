// Last updated: 09/06/2026, 19:45:12
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& b,
                                   vector<bool>& is) {
        unordered_map<string, int> mp = {{"electronics", 0},
                                         {"grocery", 1},
                                         {"pharmacy", 2},
                                         {"restaurant", 3}};
        vector<vector<string>> v(4);
        for (int i = 0; i < code.size(); i++) {
            if (!is[i] || code[i].empty())
                continue;
            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;
            auto it = mp.find(b[i]);
            if (it == mp.end())
                continue;
            v[it->second].push_back(code[i]);
        }
        vector<string> ans;
        for (auto& it : v) {
            sort(it.begin(), it.end());
            ans.insert(ans.end(), it.begin(), it.end());
        }
        return ans;
    }
};