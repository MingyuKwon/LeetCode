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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(!root) return false;

        return recursive(root, targetSum);
    }

    bool recursive(TreeNode* root, int targetSum) {
        if(!root) return (targetSum == 0);
        
        bool left = recursive(root->left, targetSum - root->val);
        bool right = recursive(root->right, targetSum - root->val);

        if(!root->left && !root->right)
        {
            return left || right;
        }else if(root->left && root->right)
        {
            return left || right;
        }else if(root->left == NULL && root->right != NULL )
        {
            return right;
        }else
        {
            return left;
        }
        
    }
};