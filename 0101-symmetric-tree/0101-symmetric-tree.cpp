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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        stack<TreeNode*> leftTreeStack;
        stack<TreeNode*> rightTreeStack;

        TreeNode* rootLeft = root->left;
        TreeNode* rootRight = root->right;

        while((rootLeft != NULL || !leftTreeStack.empty()) || (rootRight != NULL || !rightTreeStack.empty()))
        {
            if(rootLeft != NULL && rootRight != NULL)
            {
                leftTreeStack.push(rootLeft);
                rightTreeStack.push(rootRight);

                rootLeft = rootLeft->left;
                rootRight = rootRight->right;

            }else if(rootLeft == NULL && rootRight == NULL){
                TreeNode* rootLeftTemp = leftTreeStack.top();
                TreeNode* rootRightTemp = rightTreeStack.top();

                if(rootLeftTemp->val != rootRightTemp->val) return false;

                rootLeft = rootLeftTemp->right;
                rootRight = rootRightTemp->left;

                leftTreeStack.pop();
                rightTreeStack.pop();

            }else
            {
                return false;
            }
        }

        return true;

        
    }
};