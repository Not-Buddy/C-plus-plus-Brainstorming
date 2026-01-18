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
    void flatten(TreeNode* root) {

        if(root==nullptr)
            return;

        std::stack<TreeNode*> s{};
        s.push(root);
        std::vector<int> values{};

        while(!s.empty())
        {
            TreeNode* node = s.top();
            values.push_back(node->val);

            s.pop();
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);


        }

        TreeNode *flattened = new TreeNode(values[0]);

        TreeNode *node = flattened;
        for(int i{1};i<values.size();i++)
        {
            TreeNode *newNode = new TreeNode(values[i]);
            newNode->left=nullptr;
            node->right=newNode;
            node=node->right;
        }

        node->left=nullptr;

        root->val=flattened->val;
        root->left=flattened->left;
        root->right=flattened->right;
    }
};
