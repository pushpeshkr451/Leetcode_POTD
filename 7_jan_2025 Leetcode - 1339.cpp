class Solution {
public:
    const int mod = 1e9 + 7;
    long long sum;
    long long maxp;
    int total_sum(TreeNode* root) {
        if (root == NULL)
            return 0;
        return root->val + total_sum(root->left) + total_sum(root->right);
    }

    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);
        long long s1 = root->val + l + r;
        long long s2 = sum - s1;
        maxp = max(maxp,1LL*(s1 * s2));

        return s1%mod;
    }

    int maxProduct(TreeNode* root) {
        sum = total_sum(root);
        maxp = 0;

        solve(root);
        return maxp % mod;
    }
};
