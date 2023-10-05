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
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer->next && fastPointer->next->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        if(!slowPointer->next)
        {
            return true;
        }

        ListNode* previous = NULL;
        ListNode* curr = slowPointer->next;
        ListNode* next = slowPointer->next;

        while(curr)
        {
            next = curr->next;
            curr->next = previous;
            previous = curr;
            curr = next;
        }

        while(previous && head)
        {
            if(previous->val != head->val) return false;
            previous = previous->next; 
            head = head->next;
        }


        return true;
    }
};

// 여기서 핵심은 slow, fast pointer를 이용해서 listnode의 중간 지점을 찾을 수 있다는 것이다.
// fast는 2칸식, slow는 한칸씩 이동하다가 만약 fast가 더이상 전진하지 못하는 지점에 오면 리스트 길이가 짝수이면
// 절반지점 전 칸에, 홀수이면 딱 중간지점에 멈추게 된다. 이걸 이용하면, slowPointer 다음 지점부터 끝까지는 list의 후반부
// 라는 소리이고, 이 후반부만 뒤집어서 비교하면 된다는 의미이다
// 그리고 링크드 리스트 뒤집을 때 포인터가 3개가 필요한 이유는, 별거 없고 그냥 node->next를 바꾸기 전에 다음 노드를 
// 기록 할 포인터와, 이전 노드를 기억할 포인터 합쳐서 3개가 필요한거다.
// 이 포인ㄴ터 3개만 쓰기로 마음먹으면, 리스트 뒤집는 것은 매우 쉬운 작업이 된다