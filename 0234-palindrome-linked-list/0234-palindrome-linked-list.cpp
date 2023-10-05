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
    bool isPalindrome(ListNode* head) {
        vector<int> Vector;

        while(head)
        {
            Vector.push_back(head->val);
            head = head->next;
        }

        int startpointer = 0;
        int endpointer = Vector.size()- 1;

        while(startpointer < endpointer)
        {
            if(Vector[startpointer] != Vector[endpointer]) return false;
            startpointer++;
            endpointer--;
        }

        return true;
    }
};