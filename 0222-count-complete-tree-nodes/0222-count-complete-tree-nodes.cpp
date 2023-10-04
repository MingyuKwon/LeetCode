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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = countHeight(root->left);
        int rightHeight = countHeight(root->right);

        if(leftHeight == rightHeight)
        {
            return countNodes(root->right) + pow(2,leftHeight);
        }else
        {
            return  pow(2,rightHeight) + countNodes(root->left);
        }
        
    }

    int countHeight(TreeNode* root)
    {
        int n = 0;
        while(root)
        {
            root = root->left;
            n++;
        }

        return n;
    }
};
