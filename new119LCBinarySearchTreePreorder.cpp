class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		if(preorder.empty()) return nullptr;

		TreeNode *root = new TreeNode(preorder[0]);
		stack<TreeNode*> st{};
		st.push(root);

		for(int i{1};i<preorder.size();i++)
		{
			TreeNode *node = new TreeNode(preorder[i]);
			if(preorder[i]<st.top()->val)
				st.top()->left=node;
			else 
			{
				TreeNode *parent = nullptr;
				while(!st.empty()&&st.top()->val<preorder[i])
				{
					parent = st.top();
					st.pop();
				}
				parent->right = node;
			}
			st.push(node);
		}
	return root;
  }

};
