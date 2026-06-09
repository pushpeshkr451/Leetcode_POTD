// Last updated: 09/06/2026, 19:45:08
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side=2*k+1;
        int row=(n+side-1)/side;
        int col=(m+side-1)/side;
        return row*col;
    }
};