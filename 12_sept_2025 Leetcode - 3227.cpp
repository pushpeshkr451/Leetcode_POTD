class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (auto it : s) {
            if (st.count(it))
                return 1;
        }
        return 0;
    }
};
