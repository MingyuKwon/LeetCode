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
    void Recursive(TreeNode* node, vector<int>& resultVector)
    {
        if(node == NULL) return;

        if(node->left != NULL)
        {
            Recursive(node->left,resultVector);
        }

        resultVector.push_back(node->val);

        if(node->right != NULL)
        {
            Recursive(node->right,resultVector);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultVector;
        Recursive(root, resultVector);  
        return resultVector;

    }

    


};