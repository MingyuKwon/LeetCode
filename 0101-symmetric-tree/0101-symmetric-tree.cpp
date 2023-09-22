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
    bool Recursive(TreeNode* leftnode, TreeNode* rightnode ){
        if(leftnode == NULL && rightnode == NULL) return true;
        if(leftnode != NULL && rightnode == NULL) return false;
        if(leftnode == NULL && rightnode != NULL) return false;

        if(leftnode->val != rightnode->val)
        {
            return false;
        }

        if(!Recursive(leftnode->left, rightnode->right))
        {
            return false;
        }

        if(!Recursive(leftnode->right, rightnode->left))
        {
            return false;
        }

        return true;



    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Recursive(root->left, root->right);
    }
};