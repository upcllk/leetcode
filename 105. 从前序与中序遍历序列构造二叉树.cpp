#include <bits/stdc++.h>

using namespace std;

/**
 * 递归计算坐标范围的时候容易出错，多注意下
*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        const int size = preorder.size();
        return buildTree(preorder, inorder, 0, size - 1, 0, size - 1);
    }

private:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, 
                        int left1, int right1, 
                        int left2, int right2) {
        if(left1 > right1 || left2 > right2) {
            return nullptr;
        }
        int val = preorder[left1];
        TreeNode* root = new TreeNode(val);
        vector<int>::const_iterator ite = find(inorder.begin() + left2, inorder.begin() + right2 + 1, val);
        int pos = distance(inorder.begin(), ite);
        root->left = buildTree(preorder, inorder, left1 + 1, pos - left2 + left1 - 1, left2, pos - 1);
        root->right = buildTree(preorder, inorder, pos - left2 + left1 + 1, right1, pos + 1, right2);
        return root;
    }

};

int main() {
    Solution solution;

    return 0;
}