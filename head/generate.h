//generate test bench

void generate(ListNode* head,int n) {
    if(n == 0) return;
    ListNode *h = head;
    while(n--) {
	ListNode *t = new ListNode(rand()%10000);
	h->next = t;
	h = h->next;
    }
    return;
}

void generate(vector<int>& nums,int n) {
    for(int i = 0;i < n;i++)
	nums.push_back(rand()%10000);
}

void generate(vector<vector<int>>& res,int n,int m) {
    if(n == 0) return;
    for(int i = 0;i < n;i++) {
	vector<int> nums;
	for(int j = 0;j < m;j++)
	    nums.push_back(rand()%10000);
	res.push_back(nums);
    }
}

TreeNode* generate_solve(int k,int n) {
    if(k == n) return NULL;
    TreeNode *root = new TreeNode(rand()%10000);
    root->left = generate_solve(k+1,n);
    root->right = generate_solve(k+1,n);
    return root;
}

TreeNode* generate(int n) {
    return generate_solve(0,n);
}

