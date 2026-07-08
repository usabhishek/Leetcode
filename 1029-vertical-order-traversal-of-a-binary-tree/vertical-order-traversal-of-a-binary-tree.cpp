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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map < int, multiset<int> > > nodes; 
        // first map stores horizontal distance(-1,0,1)
        // second map store level and corresponding verticals
        //use multiset instead of vector because we need our values sorted for each veritical

        queue< pair <TreeNode*, pair <int, int> > > q;
        // frontNode, horizontal distance, level

        vector<vector<int>> res;

        if (root != NULL)
            q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair <TreeNode*, pair <int, int> > temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(frontNode->val);

            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1))); 
                // hd will decrease if we move left side of root and level will increase in every case
            }

            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }

         for (auto& it : nodes) {
            vector<int> curr;
            
            for (auto& j : it.second){
                for (auto& l : j.second) curr.push_back(l); // store each vertical in curr
            }
            res.push_back(curr);
        }

        return res;
    }
};