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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int vectorSize = nums.size();

        if(vectorSize == 0) return NULL;
        if(vectorSize == 1) return new TreeNode(nums[0]);

        int mid = vectorSize / 2;

        TreeNode* treeNode = new TreeNode(nums[mid]);

        vector<int> leftVector(nums.begin(), nums.begin() + mid);
        vector<int> rightVector(nums.begin() + mid + 1 , nums.end());

        treeNode->left = sortedArrayToBST(leftVector);
        treeNode->right = sortedArrayToBST(rightVector);

        return treeNode;
    }
};