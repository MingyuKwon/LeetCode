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
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : generate_trees(1,n);
    }

    vector<TreeNode*> generate_trees(int start, int end)
    {
        if(start > end) return {nullptr};

        vector<TreeNode*> allTreeNodes;
        
        for(int i=start; i <= end; i++)
        {
            // 여기서 먼저 헤드가 될 놈들 정한다
        
            vector<TreeNode*> beforeTreeNodes = generate_trees(start, i-1);
            vector<TreeNode*> afterTreeNodes = generate_trees(i+1, end);

            for(TreeNode* beforeTreeNode : beforeTreeNodes)
            {
                for(TreeNode* afterTreeNode : afterTreeNodes)
                {
                    TreeNode* headNode = new TreeNode(i);
                    headNode->left = beforeTreeNode;
                    headNode->right = afterTreeNode;

                    allTreeNodes.push_back(headNode);
                }
            }
        }

        return allTreeNodes;
    }
};