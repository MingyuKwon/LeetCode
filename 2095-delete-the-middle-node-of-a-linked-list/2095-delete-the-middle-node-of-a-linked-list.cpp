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

    // 그냥 index로 중간 값을 찾아도 좋지만, fast slow pointer를 사용하면 더 좋다
    // fast slow pointer는 원래 사이클을 찾기 위한 방법이지만, 사이클이 없어도 특성 이용가능
    // slow는 fast의 절반을 가므로, 최종적으로 slow는 직선 링크드 리스트에서 중간점에서 멈추게 될 것이다.  
    // 따라서 slow에 뒤에 붙는 previous pointer 하나를 가지고 진행하면 된다
};