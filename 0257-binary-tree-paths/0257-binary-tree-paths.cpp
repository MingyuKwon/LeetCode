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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> Vector;
        string str  = to_string(root->val);

        if(!root->left && !root->right) Vector.push_back(str);

        Recursive(root->left,Vector, str);
        Recursive(root->right,Vector, str);

        return Vector;
    }

    void Recursive(TreeNode* root,vector<string>& VECTOR, string str)
    {
        if(!root) return;

        str += "->";
        str += to_string(root->val);

        if(!root->left && !root->right) VECTOR.push_back(str);

        Recursive(root->left,VECTOR, str);
        Recursive(root->right,VECTOR, str);
    }
};