class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        if (m == 0) return 0;

        int count = 0;
        int prevRowDevices = 0;
        for (int i = 0; i < m; i++) {
            int currentRowDevices = 0;

            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') {
                    currentRowDevices++;
                }
            }

            if (currentRowDevices > 0) {
                count += prevRowDevices * currentRowDevices;
                prevRowDevices = currentRowDevices;
            }
        }

        return count;

    }
};
