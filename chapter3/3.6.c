#include "../head/show.h"

ListNode* generate(int n) {
    if(n == 0) return NULL;
    ListNode *root = new ListNode(rand()%10000);
    root->next = generate(n-1);
    return root;
}

vector<ListNode*> generate(int n,int m,int k) {
    ListNode *root = generate(k);
    ListNode *left = generate(n);
    ListNode *right = generate(m);
    ListNode *first = left,*last = right;
    while(first->next) first = first->next;
    while(last->next) last = last->next;
    first->next = root;
    last->next = root;
    vector<ListNode*> res = {left,right};
    return res;
}

bool isCross1(ListNode* l1,ListNode* l2) {
    if(l1 == NULL) return false;
    if(l2 == NULL) return false;
    ListNode *first = l1,*last = l2;
    while(first) {
	last = l2;
	while(last) {
	    if(first == last) return true;
	    last = last->next;
	}
	first = first->next;
    }
    return false;
}

bool isCross2(ListNode* l1,ListNode* l2) {
    unordered_map<ListNode*,int> res;
    while(l1) {
	res[l1] = 1;
	l1 = l1->next;
    }
    while(l2) {
	if(res.find(l2) != res.end()) return true;
	l2 = l2->next;
    }
    return false;
}

bool isCross3(ListNode* l1,ListNode* l2) {
    ListNode *h = l2;
    while(h->next) h = h->next;
    h->next = l2;
    while(l1) {
	if(l1 == l2) {
	    h->next = NULL;
	    return true;
	}
	l1 = l1->next;
    }
    h->next = NULL;
    return false;
}

bool isCross4(ListNode* l1,ListNode* l2) {
    while(l1->next) l1 = l1->next;
    while(l2->next) l2 = l2->next;
    return l1 == l2;
}

int main() {
    int n = 23,m = 56,k = 16;
    vector<ListNode*> res = generate(n,m,k);
    ListNode *l1 = generate(n+k),*l2 = generate(m+k);
    int start = clock();
    cout << isCross1(res[0],res[1]) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross2(res[0],res[1]) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross3(res[0],res[1]) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross4(res[0],res[1]) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross1(l1,l2) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross2(l1,l2) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross3(l1,l2) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << isCross4(l1,l2) << endl;
    cout << "time: " << clock()-start << endl;
    return 0;
}
