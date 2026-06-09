// Last updated: 09/06/2026, 19:43:41
class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());

        int m=stoi(s);

        return abs(n-m);
    }
};