// Last updated: 09/06/2026, 19:44:34
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long mul = 1;
        while (n != 0) {
            int rem = n % 10;
            n /= 10;
            rem = rem * mul;
            mul *= 10;
            if (rem != 0)
                ans.push_back(rem);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};