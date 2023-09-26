/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> hasMap;

        while(headA)
        {
            hasMap[headA] = true;
            headA = headA->next;
        }

        while(headB)
        {
            if(hasMap.find(headB) != hasMap.end()) return headB;
            headB = headB->next;
        }

        return NULL;
    }
};