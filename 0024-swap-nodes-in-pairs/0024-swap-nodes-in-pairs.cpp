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
        if(!head || !head->next) return head;

        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }

    // 재귀는 작은 단위를 다루는 함수만 시킬 수 있는 것이 아니다
    // 마치 분할 정복처럼 1~n을 다루는 문제를 2~n , 3~n .... n-1~n 을 다루는 문제로 바꿀 수 있다
    // 즉 전체를 변형하는 함수를 작은 범위에서 또 호출해서 푸는 재귀도 있는 것이다!
};