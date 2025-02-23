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
    ListNode* ans = nullptr;

    ListNode* solve(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* next = solve(head->next);
        if(next)
        {
            next->next = head;
        }else
        {
            ans = head;
        }

        head->next = nullptr;

        return head;
    }

    ListNode* reverseList(ListNode* head)
    {
        solve(head);
        return ans;
    }
};