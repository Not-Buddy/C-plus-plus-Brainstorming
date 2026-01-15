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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
		
		if(root == nullptr) return res;

		std::queue<TreeNode*> q{};
        q.push(root);

        bool flag = true;

        while(!q.empty())
        {

            int CurrentSize = q.size();
            vector<int> currentLevel(CurrentSize);
            
            for(int i{0}; i<CurrentSize;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                int index = flag ? i : (CurrentSize -1 -i);
                currentLevel[index] = node -> val;

                if(node -> left) q.push(node->left);
                if(node -> right) q.push(node->right);
            }
            res.push_back(currentLevel);
            flag = !flag;
        }
        return res;
    }
};
