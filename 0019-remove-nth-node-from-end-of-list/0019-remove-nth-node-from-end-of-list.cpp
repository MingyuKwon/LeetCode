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
    int targetIndex;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        targetIndex = n;
        if(Recursive(NULL, head) > 0)
        {
            return head;
        }
        
        return head->next;
    }

    int Recursive(ListNode* previousNode, ListNode* currentNode)
    {
        if(currentNode == NULL) return 1;

        int value = Recursive(currentNode, currentNode->next);

        if(value == targetIndex) 
        {
            if(previousNode)
            {
                previousNode->next = currentNode->next;
            }else
            {
                return 0;
            }
            
        }
        return value + 1;
    }
    
    // LinkedList에서 노드를 지울 떄는 반드시 반드시 헤더 노드를 지우는 경우를 감안해야 한다!
};