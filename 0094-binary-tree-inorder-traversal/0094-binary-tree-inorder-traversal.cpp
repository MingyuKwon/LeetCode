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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultVector;
        
        stack<TreeNode*> STACK;

        while(!STACK.empty() || root != NULL)
        {
            if(root != NULL)
            {
                STACK.push(root);
                root = root->left;
            }else
            {
                TreeNode* topStackNode = STACK.top();
                resultVector.push_back(topStackNode->val);
                STACK.pop();
                root = topStackNode->right;
            }
        }

        return resultVector;

    }

    


};