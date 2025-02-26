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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(ans, 0, root);
        return ans;
    }

    void solve(vector<vector<int>>& ans, int level, TreeNode* root)
    {   
        if(root == nullptr) return;

        if(ans.size() == level) ans.push_back(vector<int>());

        ans[level].push_back(root->val);
        solve(ans, level+1, root->left);
        solve(ans, level+1, root->right);
    }
};