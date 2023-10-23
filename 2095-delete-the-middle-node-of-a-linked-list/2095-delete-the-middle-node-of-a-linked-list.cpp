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
    ListNode* deleteMiddle(ListNode* head) {
        int middle = 0;
        ListNode* temp = head;
        while(temp)
        {
            middle++;
            temp = temp->next;
        } 

        if(middle == 1) return NULL;

        temp = head;
        ListNode* previousNode = NULL;
        int index = 0;
        middle = middle / 2;
        while(temp)
        {
            if(middle == index)
            {
                previousNode->next = temp->next;
            }

            previousNode = temp;
            temp = temp->next;
            index++;
        }

        return head;
    }
};