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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> HashMap;

        while(head)
        {
            if(HashMap.find(head) == HashMap.end())
            {
                HashMap[head] = false;
            }else
            {
                return true;
            }

            head = head->next;
        }

        return false;
    }
};