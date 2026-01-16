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
    unordered_map<int,int> pos;
    int preIndex=0;
 
    TreeNode* build(int L, int R, const vector<int>preorder)
    {
        if(L>R) return nullptr;

        int rootVal=preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];
        root->left = build(L, mid-1, preorder);
        root->right = build(mid+1, R, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.empty()) return nullptr;
        
        pos.clear();
        for(int i{0};i<inorder.size();i++)
            pos[inorder[i]]=i;

        preIndex=0;
        
        return build(0,(int)inorder.size()-1, preorder);
    }
};
