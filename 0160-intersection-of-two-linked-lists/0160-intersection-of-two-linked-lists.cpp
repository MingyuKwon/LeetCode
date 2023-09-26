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
    //getting the tail
    ListNode* tail = headA;
    while(tail->next){
        tail = tail->next;
    }

    //creating a loop
    tail->next = headA;

    //detecting and finding the intersection
    ListNode *fast = headB, *slow = headB;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) {
            slow = headB;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            //undoing the loop
            tail->next = NULL;
            return slow;
        };
    }
    tail->next = NULL;
    return NULL;

    }
};


//Find the tail.
//Connect the tail with any of the head which creates a loop.
//Using the other head, find intersection point of the loop.
//Undo the loop, by setting tail->next = NULL
//Return the intersection node.

// 1. 핵심 아이디어. 교차점 문제를 사이클 문제로 바꿔 버리는 생각
// 2. 사이클 문제로 바꾼 후에, 플로이드의 토끼와 거북이 알고리즘을 사용해서 결국 사이클이 존재하면 
//         어디에서든 만날 것을 생각
// 3. 그리고 그렇게 만나는 점에서 사이클의 시작점까지의 거리와, 링크드리스트 시작지점에서 사이클 시작 점과의 
//      거리가 같다는 플로이드 토끼와 거북이 확장 알고리즘을 이용해서 사이클의 시작점을 구한다
// 4. 그리고 그 사이클의 시작점이 결국 두 링크드 리스트의 교차점이 될 것이다