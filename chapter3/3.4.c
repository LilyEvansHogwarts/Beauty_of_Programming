#include "../head/show.h"

ListNode* generate(int n) {
    ListNode *first = new ListNode(0);
    ListNode *h = first;
    while(n--) {
	ListNode *t = new ListNode(rand()%10000);
	h->next = t;
	h = h->next;
    }
    return first->next;
}

ListNode* deleteCurrentNode(ListNode* pCurrent) {
    ListNode *t = pCurrent->next;
    pCurrent->val = t->val;
    pCurrent->next = t->next;
    delete t;
    return pCurrent;
}

int main() {
    ListNode *head = generate(10);
    show(head);
    deleteCurrentNode(head->next->next);
    show(head);
    return 0;
}
