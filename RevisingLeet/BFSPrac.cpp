#include <iostream>
#include <vector>
#include <queue>
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

std::vector<int> bfs(TreeNode* root)
{
	if(root==nullptr)
		return {};
	std::queue<TreeNode*> q{};
	q.push(root);

	std::vector<int> order{};
	while(!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();
		order.push_back(node->val);

		if(node->left)
			q.push(node->left)
		if(node->right)
			q.push(node->right);

	}
	return order;
}
