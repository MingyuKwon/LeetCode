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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        // 먼저 linked list 전체 길이를 구함
        int length = 1;
        ListNode* current = head;
        while(current->next)
        {
            current = current->next;
            length++;
        }

        // 마지막 노드 참조를 저장해 두고 있다가 마지막에 끊음
        // 마지막 노드의 이후 노드를 첫번쨰 노드로 이은 다음에 일을 진행
        ListNode* lastNode = current;
        lastNode->next = head;
        current = head;

        // 그리고 k를 전체 길이 만큼 나머지 연산해서 실제로 넘어가야 하는 길이를 구함
        k %= length;
        k = length - k;
        k %= length;

        ListNode* previousNode = lastNode;
        // 생각해 보니 이거 그냥 원 형태로 만들고 끊는 위치를 잘 정하고 끊은 거 첫번쨰를 반환하면 되는거 아닌가?
        while(k > 0)
        {
            previousNode = current;
            current = current->next;
            k--;
        }

        previousNode->next = NULL;
        return current;
    }
};