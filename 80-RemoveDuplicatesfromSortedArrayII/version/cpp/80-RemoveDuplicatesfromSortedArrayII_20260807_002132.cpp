// Last updated: 07/08/2026, 00:21:32
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
13    ListNode* deleteDuplicates(ListNode* head) {
14        if (!head)
15            return head;
16        ListNode* temp = head;
17        unordered_map<int, int> mp;
18
19        while (temp) {
20            int num = temp->val;
21            mp[num]++;
22            temp = temp->next;
23        }
24        ListNode* ans = new ListNode();
25        ListNode* final = ans;
26
27        while (head) {
28
29            int value = head->val;
30            if (mp[value] == 1) {
31                ans->next = new ListNode(value);
32                ans = ans->next;
33            }
34            head = head->next;
35        }
36        return final->next;
37    }
38};