// Last updated: 10/09/2026, 08:19:00
1class Solution {
2public:
3int ans;
4pair<int,int>solve(TreeNode* root){
5    if(root==NULL)return {0,0};
6
7    auto it1=solve(root->left);
8    auto it2=solve(root->right);
9
10    int totalsum=it1.first+it2.first+root->val;
11    int count=it1.second+it2.second+1;
12
13    if((totalsum)/count==root->val)ans++;
14    return {totalsum,count};
15}
16    int averageOfSubtree(TreeNode* root) {
17        if(!root)
18           return 0;
19        ans=0;
20        solve(root);
21        return ans;
22    }
23};