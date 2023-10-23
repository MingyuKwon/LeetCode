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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* previous = NULL;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            previous = slow;
            slow = slow->next;
        }

        if(previous)
        {
            previous->next = slow->next;
        }else
        {
            head = NULL;
        }

        return head;
    }
};