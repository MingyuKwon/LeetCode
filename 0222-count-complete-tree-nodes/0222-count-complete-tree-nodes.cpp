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

        TreeNode* temp = root;

        int leftHeight = 0;
        int rightHeight = 0;

        while(temp)
        {
            temp = temp->left;
            leftHeight++;
        }

        temp = root;
        while(temp)
        {
            temp = temp->right;
            rightHeight++;
        }

        if(leftHeight == rightHeight) return pow(2,leftHeight) - 1;
        
        return countNodes(root->right) + countNodes(root->left) + 1;

    }
};

//핵심은 완전 이진 트리에서는 좌우 높이를 계산해서 같다면 그 즉시 노드의 개수를 알 수 있다는 것
// 그리고 완전 이진 트리라고 확정이 나면 좌우, 한쪽은 반드시 좌우 높이가 동일한 경우가 생긴다
// 따라서 좌우 모두 재귀를 돌려도 한쪽은 재귀에 안들어가고 바로 값을 반환하기에 높이만큼인 lonN 만큼만 호출되고 끝날 수 있다