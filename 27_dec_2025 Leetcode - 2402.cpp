class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        set<pair<long long, int>> meeting;
        set<int> vacant;
        for (int i = 0; i < n; i++) {
            vacant.insert(i);
        }

        map<int, int> mp;

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;

            while (!meeting.empty() && meeting.begin()->first <= start) {
                int room = meeting.begin()->second;
                vacant.insert(room);
                meeting.erase(meeting.begin());
            }

            if (!vacant.empty()) {
                int room = *vacant.begin();
                vacant.erase(room);
                meeting.insert({end, room});
                mp[room]++;
            } else {
                auto it = *meeting.begin();
                long long new_start = it.first;
                int room = it.second;
                meeting.erase(meeting.begin());
                meeting.insert({new_start + duration, room});
                mp[room]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp[i] > mp[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};
