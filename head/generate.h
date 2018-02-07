#include "../show.h"

//generate test bench

ListNode* generate(int n) {
    ListNode *head = new ListNode(0);
    ListNode *h = head;
    while(n--) {
	ListNode *t = new ListNode(rand()%10000);
	h->next = t;
	h = h->next;
    }
    return head->next;
}

vector<int> generate(int n) {
    vector<int> res(n,0);
    for(int i = 0;i < n;i++)
	res[i] = rand()%10000;
    return res;
}

vector<vector<int>> generate(int n,int m) {
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	    res[i][j] = rand()%10000;
    return res;
}
