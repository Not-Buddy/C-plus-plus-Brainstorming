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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        std::queue<TreeNode*> q{};
        vector<vector<int>> res{};
        q.push(root);

        while(!q.empty())
        {
            int LevelSize = q.size();
            std::vector<int> currentLevel;

            for(int i{0};i<LevelSize;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if(node->left != nullptr)
                        q.push(node->left);
                if(node->right != nullptr)
                        q.push(node->right);
            }
            res.push_back(currentLevel);
        }
        return res;
    }
};
