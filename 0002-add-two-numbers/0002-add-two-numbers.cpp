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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int upper = 0;
        ListNode* temp = l1;
        ListNode* head = temp;

        while(l1 || l2)
        {
            if(!l1)
            {
                int val = (l2->val + upper) % 10;
                upper = (l2->val + upper) / 10;
                temp->val = val;

                l2 = l2->next;
                temp->next = l2;
            }else if(!l2)
            {
                int val = (l1->val + upper) % 10;
                upper = (l1->val + upper) / 10;
                temp->val = val;

                l1 = l1->next;
                temp->next = l1;
            }else
            {
                int val = (l1->val + l2->val + upper) % 10;
                upper = (l1->val + l2->val + upper) / 10;
                temp->val = val;

                l1 = l1->next;
                l2 = l2->next;

                if(l1){
                    temp->next = l1;
                }else
                {
                    temp->next = l2;
                }
            }
            if(temp->next) temp = temp->next;
        }

        if(upper > 0) 
        {
            temp->next = new ListNode(1);
        }

        return head;
    }
};