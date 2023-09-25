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
    bool isBalanced(TreeNode* root) {
        return (checkDepth(root) != -1);
    }

    int checkDepth(TreeNode* root)
    {
        if(!root) return 0;

        int leftDepth = checkDepth(root->left);
        int rightDepth = checkDepth(root->right);

        if(leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1 ) return -1;

        return max(leftDepth, rightDepth) + 1;

    }
};