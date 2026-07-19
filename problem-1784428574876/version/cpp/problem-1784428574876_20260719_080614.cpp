// Last updated: 19/07/2026, 08:06:14
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
14    int dfs(TreeNode* root,int &cnt){
15        if(!root)return 0;
16
17        int l=dfs(root->left,cnt);
18        int r=dfs(root->right,cnt);
19
20        int mx=max({root->val,l,r});
21
22        if(root->val==mx)cnt++;
23
24        return mx;
25    }
26    int countDominantNodes(TreeNode* root) {
27        
28        int cnt=0;
29        dfs(root,cnt);
30        return cnt;
31        
32    }
33};