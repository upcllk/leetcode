#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTreeFromPreOrder(const vector<int>& preOrder, int& index) {
        if(preOrder.empty() || index >= preOrder.size()) {
            return nullptr;
        }
        if(preOrder[index] == 0) {
            ++ index;
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[index]);
        ++ index;
        root->left = buildTreeFromPreOrder(preOrder, index);
        root->right = buildTreeFromPreOrder(preOrder, index);
        return root;
    }
};

void getPreOrder(TreeNode* root) {
    if(root == nullptr) {
        cout << 0 << " ";
        return;
    }
    cout << root->val << " ";
    getPreOrder(root->left);
    getPreOrder(root->right);
}

int main() {
    Solution solution;
    int index = 0;
    vector<int> preOrder = {1,5,8,0,0,0,6,0,0};
    TreeNode* result = solution.buildTreeFromPreOrder(preOrder, index);
    getPreOrder(result);
    cout << endl;
    return 0;
}