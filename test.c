#include "head/show.h"
#include "head/generate.h"

ListNode* reverseKGroup(ListNode *head,int k) {
    if(!head || k == 1) return head;
    int num = 0;
    ListNode *preheader = new ListNode(0);
    preheader->next = head;
    ListNode *cur = preheader,*nex,*tmp,*pre = preheader;
    while(cur = cur->next) num++;
    while(num >= k) {
	cur = pre->next;
	nex = cur->next;
	for(int i = 1;i < k;i++) {
	    tmp = nex->next;
	    nex->next = pre->next;
	    pre->next = nex;
	    cur->next = tmp;
	    nex = tmp;
	}
	pre = cur;
	num -= k;
    }
    return preheader->next;
}

int get_width(TreeNode* root) {
    if(root == NULL) return 0;
    int left = get_width(root->left),right = get_width(root->right);
    return left+right+1;
}


int main() {
    ListNode *head = generate(10);
    show(head);
    ListNode *res = swapPairs(head);
    show(res);
    return 0;
}
