// Last updated: 31/08/2026, 14:54:38
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        ListNode* prev = head;
15        ListNode* cur = head->next;
16
17        int idx = 1;
18
19        int firstCritical = -1;
20        int lastCritical = -1;
21        int minDist = INT_MAX;
22
23        while(cur->next){
24            ListNode* next = cur->next;
25
26            bool isMax = cur->val > prev->val && cur->val > next->val;
27            bool isMin = cur->val < prev->val && cur->val < next->val;
28
29            if(isMax || isMin){
30                if(lastCritical == -1){
31                    firstCritical = idx;
32                }
33                else {
34                    minDist = min(minDist, idx - lastCritical);
35                }
36
37                lastCritical = idx;
38            }
39
40            prev = cur;
41            cur = next;
42            idx++;
43        }
44
45        if(firstCritical == -1 || firstCritical == lastCritical){
46            return {-1, -1};
47        }
48
49        int maxDist = lastCritical - firstCritical;
50
51        return {minDist, maxDist};
52    }
53};