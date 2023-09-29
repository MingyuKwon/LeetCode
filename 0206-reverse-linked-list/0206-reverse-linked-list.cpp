/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return Recursive(NULL, head);
    }

    ListNode* Recursive(ListNode* previousNode, ListNode* currentNode)
    {
        if(!currentNode) return previousNode;

        ListNode* newNode =  Recursive(currentNode, currentNode->next);
        currentNode->next = previousNode;
        return newNode;
    }
};