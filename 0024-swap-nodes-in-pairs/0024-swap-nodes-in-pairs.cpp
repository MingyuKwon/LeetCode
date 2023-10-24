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
    ListNode* swapPairs(ListNode* head) {
        bool isEven = false;

        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* preprevious = NULL;
        ListNode* next = NULL;

        while(current)
        {
            next = current->next;

            if(isEven)
            {
                if(head == previous) 
                {
                    head = current;
                }else
                {
                    preprevious->next = current;
                }

                previous->next = current->next;
                current->next = previous;

                preprevious = current;
            }else
            {
                preprevious = previous;
                previous = current;
            }

            isEven = !isEven;
            current = next;

        }

        return head;


    }
};