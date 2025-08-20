class Solution {
public:

    int height(TreeNode *node, int &diameter)
    {
        if(!node)
            return 0;
        int left_height = height(node->left,diameter);
        int right_height = height(node->right,diameter);
        diameter = std::max(diameter,left_height+right_height);

        return 1+std::max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};
