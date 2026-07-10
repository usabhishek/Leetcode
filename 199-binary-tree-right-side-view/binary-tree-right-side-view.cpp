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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q;
        // the second value will store the level

        map<int, int> mp;
        // first int will store level and the second will store value;

        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int level = it.second;
            TreeNode* frontNode = it.first;

            // if(mp.find(level) == mp.end())
            mp[level] =  frontNode->val;

            if(frontNode->left != nullptr){
                q.push({frontNode->left, level+1});
            }

            if(frontNode->right != nullptr){
                q.push({frontNode->right, level+1});
            }
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};