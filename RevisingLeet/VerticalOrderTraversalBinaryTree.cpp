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


        if(root==nullptr)
            return {};

        std::vector<std::vector<int>> res{};
        
        std::stack<tuple<TreeNode*,int,int>> st{};
        st.push({root,0 ,0});
        
        
        std::vector<tuple<int,int,int>> nodes{};
        while(!st.empty())
        {
            auto [node, col, row] = st.top();
            st.pop();
            
            nodes.push_back({col, row, node->val});

            if(node->left)
                st.push({node->left, col-1, row+1});
            if(node->right)
                st.push({node->right, col+1, row+1});
        }

        sort(nodes.begin(),nodes.end());

        int prevCol  = INT_MIN;
        for(auto [col, row, val]: nodes)
        {
            if(prevCol != col)
            {
                res.push_back({});
                prevCol = col;
            }

            res.back().push_back(val);
        }

        return res;

    }
};
