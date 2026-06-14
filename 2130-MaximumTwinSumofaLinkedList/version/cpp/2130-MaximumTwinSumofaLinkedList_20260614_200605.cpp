// Last updated: 14/06/2026, 20:06:05
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
13    int pairSum(ListNode* head) {
14        ListNode *slow = head, *fast = head;
15
16        // Find middle
17        while (fast && fast->next) {
18            slow = slow->next;
19            fast = fast->next->next;
20        }
21
22        // Reverse second half
23        ListNode *prev = nullptr;
24        while (slow) {
25            ListNode *nextNode = slow->next;
26            slow->next = prev;
27            prev = slow;
28            slow = nextNode;
29        }
30
31        // Calculate maximum twin sum
32        int ans = 0;
33        ListNode *first = head;
34        ListNode *second = prev;
35
36        while (second) {
37            ans = max(ans, first->val + second->val);
38            first = first->next;
39            second = second->next;
40        }
41
42        return ans;
43    }
44};