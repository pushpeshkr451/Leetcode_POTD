// Last updated: 20/07/2026, 21:26:38
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int sumOfLeftLeaves(TreeNode* root) {
15        if (root == nullptr)
16            return 0;
17
18        int sum = 0;
19
20        if (root->left &&
21            root->left->left == nullptr &&
22            root->left->right == nullptr) {
23            sum += root->left->val;
24        }
25
26        sum += sumOfLeftLeaves(root->left);
27        sum += sumOfLeftLeaves(root->right);
28
29        return sum;
30    }
31};