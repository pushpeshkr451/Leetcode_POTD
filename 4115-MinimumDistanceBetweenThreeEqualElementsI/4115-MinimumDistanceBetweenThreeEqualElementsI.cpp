// Last updated: 09/06/2026, 19:44:00
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < (int)nums.size(); ++i) mp[nums[i]].push_back(i);
        
        int ans = INT_MAX;
        for (auto &pr : mp) {
            auto &pos = pr.second;
            if (pos.size() < 3) continue;
            for (int i = 0; i + 2 < (int)pos.size(); ++i) {
                int dist = 2 * (pos[i+2] - pos[i]); 
                if (dist < ans) ans = dist;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
