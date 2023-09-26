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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> STACK;
        if(root) STACK.push(root);

        while(!STACK.empty())
        {
            TreeNode* stackTop = STACK.top();

            if(stackTop == nullptr)
            {
                STACK.pop();
                ans.push_back(STACK.top()->val);
                STACK.pop();
            }else
            {
                STACK.push(nullptr);
                if(stackTop->right) STACK.push(stackTop->right);
                if(stackTop->left) STACK.push(stackTop->left);
            }
        }

        return ans;
    }
};