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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* cur = dummy;
        
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
            }else
            {
                cur = cur->next; 
            }
        }

        return dummy->next;
    }

    // 단순 cur변수를 이용해서 순환하는 경우, 링크드 리스트에 전혀 변환을 주지 않고 단지 순회만 하게 된다.
    // 하지마나 cur->next를 기준으로 순환한다면, cur->next를 바꾸게 되면 cur은 단순히 변수기 때문에 값을 할당해도
    // 원본은 바뀌지 않지만, ->next는 원본을 변경하는 것이기에 리스트를 바꾸게 되는 결과가 된다
    // 따라서 만약 리스트를 변경하지 않고 그냥 탐색만 할 경우, cur을 이용해 탐색하고
    // 만약 리스트를 변경해야하는 경우 head이전에 하나 만들어 놓고, next 위주로 탐색을 돌아가게 하면 된다
};