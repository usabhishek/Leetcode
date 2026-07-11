/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;

        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;

        bool left = solve(p->left, q->right);
        bool right = solve(p->right, q->left);

        bool curr = p->val == q->val;

        if(left && curr && right) return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        bool res = solve(root->left, root->right);
        return res;
    }
};