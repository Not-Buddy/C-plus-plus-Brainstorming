#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    Node* root = new Node(postorder[n - 1]);
    stack<Node*> s;
    s.push(root);

    for (int i = n - 2; i >= 0; i--) {
        Node* node = new Node(postorder[i]);
        Node* curr = s.top();

        if (postorder[i] > curr->data) {
            curr->right = node;
        } else {
            while (!s.empty() && postorder[i] < s.top()->data) {
                curr = s.top();
                s.pop();
            }
            curr->left = node;
        }
        s.push(node);
    }

    queue<Node*> q;
    q.push(root);
    stack<vector<int>> st;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        while (size-- > 0) {
            Node* curr = q.front();
            q.pop();
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
            level.push_back(curr->data);
        }
        st.push(level);
    }

    st.pop();
    if (!st.empty()) {
        vector<int> ans = st.top();
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }

    return 0;
}