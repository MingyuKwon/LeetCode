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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        } 

        ListNode* firstNode = NULL;
        ListNode* lastNode = NULL;

        temp = head;
        int index = 0;
        while(temp)
        {
            index++;
            if(index == k) firstNode = temp;
            if(index == size - k + 1) lastNode = temp;
            temp = temp->next;
        }

        int tempValue = firstNode->val;
        firstNode->val = lastNode->val;
        lastNode->val = tempValue;

        return head;
    }

    
};