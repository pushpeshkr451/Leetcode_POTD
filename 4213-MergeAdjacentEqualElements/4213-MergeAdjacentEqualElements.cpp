// Last updated: 09/06/2026, 19:43:29
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;

        for(long long x : nums){
            st.push_back(x);

            while(st.size() >= 2 && st.back() == st[st.size()-2]){
                long long v = st.back();
                st.pop_back();
                st.back() += v;
            }
        }

        return st;
    }
};