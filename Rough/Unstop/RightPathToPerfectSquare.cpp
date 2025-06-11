#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int root = sqrt(num);
    return root * root == num;
}

string user_logic(int M, vector<int>& nodes) {
    TreeNode* root = buildTree(nodes);
    if (!root) return "NO";
    vector<int> path;
    TreeNode* current = root;
    while (current) {
        path.push_back(current->val);
        if (!current->right) break;
        current = current->right;
    }
    int sum = 0;
    for (int val : path) {
        sum += val;
    }
    if (isPerfectSquare(sum)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int M;
    cin >> M;
    vector<int> nodes(M);
    for (int i = 0; i < M; ++i) {
        string val;
        cin >> val;
        if (val == "N") {
            nodes[i] = -1;
        } else {
            nodes[i] = stoi(val);
        }
    }
    string result = user_logic(M, nodes);
    cout << result << endl;
    return 0;
}