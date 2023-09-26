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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> STACK;
        
        while( root || !STACK.empty())
        {
            if(root)
            {
                ans.push_back(root->val);
                STACK.push(root);
                root = root->left;
            }else
            {
                TreeNode* stackTop = STACK.top();
                STACK.pop();
                root = stackTop->right;
            }
            
        }

        return ans;
    }
};