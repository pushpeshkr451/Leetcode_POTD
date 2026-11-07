// Last updated: 07/11/2026, 13:25:05
1class Solution {
2public:
3    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
4    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
5     priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> q;
6        queue<int> currtasks;
7        for(int i = 0; i < servers.size(); i++) {
8            pq.push({servers[i], i});
9        }
10        vector<int> ans;
11        long long currtime = 0;
12        currtasks.push(tasks[0]);
13        int i=1;
14        while(currtasks.size()>0) {
15            while(q.size()>0 && q.top().first <= currtime) {
16                pq.push({q.top().second.first,q.top().second.second});
17                q.pop();
18            }
19            while(pq.size()>0 && currtasks.size()>0) {
20                int time = currtasks.front();
21                currtasks.pop();
22                auto it = pq.top();
23                pq.pop();
24                ans.push_back(it.second);
25                q.push({currtime + time,{it.first, it.second}});
26            }
27            if(pq.empty() && currtasks.size()>0) {
28                currtime = q.top().first;
29                while(i<tasks.size() && i<=currtime){
30                    currtasks.push(tasks[i]);
31                    i++;
32                }
33            }
34            else {
35                currtime++;
36                 if(i<tasks.size()){
37                currtasks.push(tasks[i]);
38                i++;
39            }
40            }
41        }
42        return ans;
43    }
44};