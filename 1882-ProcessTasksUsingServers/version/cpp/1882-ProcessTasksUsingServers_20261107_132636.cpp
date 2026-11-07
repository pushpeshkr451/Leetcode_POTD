// Last updated: 07/11/2026, 13:26:36
1class Solution {
2public:
3    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
4        priority_queue<pair<int, int>, vector<pair<int, int>>,
5                       greater<pair<int, int>>>
6            pq;
7        priority_queue<pair<long long, pair<int, int>>,
8                       vector<pair<long long, pair<int, int>>>,
9                       greater<pair<long long, pair<int, int>>>>
10            q;
11        queue<int> currtasks;
12        for (int i = 0; i < servers.size(); i++) {
13            pq.push({servers[i], i});
14        }
15        vector<int> ans;
16        long long currtime = 0;
17        currtasks.push(tasks[0]);
18        int i = 1;
19        while (currtasks.size() > 0) {
20            while (q.size() > 0 && q.top().first <= currtime) {
21                pq.push({q.top().second.first, q.top().second.second});
22                q.pop();
23            }
24            while (pq.size() > 0 && currtasks.size() > 0) {
25                int time = currtasks.front();
26                currtasks.pop();
27                auto it = pq.top();
28                pq.pop();
29                ans.push_back(it.second);
30                q.push({currtime + time, {it.first, it.second}});
31            }
32            if (pq.empty() && currtasks.size() > 0) {
33                currtime = q.top().first;
34                while (i < tasks.size() && i <= currtime) {
35                    currtasks.push(tasks[i]);
36                    i++;
37                }
38            } else {
39                currtime++;
40                if (i < tasks.size()) {
41                    currtasks.push(tasks[i]);
42                    i++;
43                }
44            }
45        }
46        return ans;
47    }
48};