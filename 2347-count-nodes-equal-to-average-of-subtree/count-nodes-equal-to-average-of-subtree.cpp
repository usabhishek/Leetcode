/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (root == NULL)
            return {0, 0};

        // {sum, count}
        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};