// Last updated: 09/06/2026, 19:42:53
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n= matrix.size();

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1)cnt++;
            }
            ans[i]=cnt;
        }

        return ans;
    }
};