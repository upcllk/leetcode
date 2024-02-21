#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty() || postorder.size() != inorder.size()) {
            return nullptr;
        }
        const int size = inorder.size();
        return buildTree(inorder, postorder, 0, size - 1, 0, size - 1);
    }

private:
    TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder, 
                        int left1, int right1, 
                        int left2, int right2) {
        if(left1 > right1 || left2  > right2) {
            return nullptr;
        }
        int value = postorder[right2];
        TreeNode* root = new TreeNode(value);
        vector<int>::const_iterator ite = find(inorder.begin() + left1, inorder.begin() + right1 + 1, value);
        int pos = distance(inorder.begin(), ite);
        root->left = buildTree(inorder, postorder, left1, pos - 1, left2, pos - left1 + left2 - 1);
        root->right = buildTree(inorder, postorder, pos + 1, right1, pos - left1 + left2, right2 - 1);
        return root;
    }
};

int main() {
    Solution solution;

    return 0;
}