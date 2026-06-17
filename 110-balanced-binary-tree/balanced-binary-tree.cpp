class Solution {
private:
    pair<bool, int> isBinaryTreeBalanced(TreeNode* root){

        if(root == NULL){
            return {true, 0};
        }

        auto left = isBinaryTreeBalanced(root->left);
        auto right = isBinaryTreeBalanced(root->right);

        bool leftBalanced = left.first;
        bool rightBalanced = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> res;

        res.first = leftBalanced && rightBalanced && diff;
        res.second = max(left.second, right.second) + 1;

        return res;
    }

public:
    bool isBalanced(TreeNode* root) {
        return isBinaryTreeBalanced(root).first;
    }
};