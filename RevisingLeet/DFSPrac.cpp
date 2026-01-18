#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> dfs(TreeNode* root) {
    if(root == nullptr)
        return {};
    
    std::stack<TreeNode*> s;
    s.push(root);
    std::vector<int> values;
    
    while(!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        values.push_back(node->val);
        
        // Push RIGHT first, then LEFT (so left is processed first)
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }
    
    return values;
}

int main() {
    // Build tree:    1
    //               / \
    //              2   5
    //             / \   \
    //            3   4   6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    std::vector<int> result = dfs(root);
    
    std::cout << "DFS Preorder: ";
    for(int val : result) {
        std::cout << val << " ";
    }
    // Expected: 1 2 3 4 5 6
    
    return 0;
}

