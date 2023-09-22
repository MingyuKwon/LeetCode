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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL) return head;
        
        int num = head->val;
        ListNode* returnPointer = head;
        
        ListNode* previousNode = head;
        head = head->next;

        while(head != NULL)
        {
            if(num == head->val)
            {
                previousNode->next = head->next;
            }else
            {
                num = head->val;
                previousNode = head;
            }

            head = head->next;
        }
        
        
        return returnPointer;
    }
};