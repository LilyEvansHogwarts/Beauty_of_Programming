#include "../head/show.h"

int printNodeAtLevel(TreeNode* root,int level) {
    if(!root || level < 0) return 0;
    if(level == 0) {
	cout << root->val << " ";
	return 1;
    }
    return printNodeAtLevel(root->left,level-1) + printNodeAtLevel(root->right,level-1);
}

void printNodeByLevel1(TreeNode* root,int depth) {
    for(int i = 0;i < depth;i++) {
	printNodeAtLevel(root,i);
	cout << endl;
    }
}

void printNodeByLevel2(TreeNode* root) {
    for(int i = 0;;i++) {
	if(!printNodeAtLevel(root,i))
	    break;
	cout << endl;
    }
}

void printNodeByLevel3(TreeNode* root) {
    if(root == NULL) return;
    vector<TreeNode*> res;
    res.push_back(root);
    int last = 1,cur = 0;
    while(cur < res.size()) {
	last = res.size();
	while(cur < last) {
	    cout << res[cur]->val << " ";
	    if(res[cur]->left)
		res.push_back(res[cur]->left);
	    if(res[cur]->right)
		res.push_back(res[cur]->right);
	    cur++;
	}
	cout << endl;
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

int main() {
    int n = 4;
    TreeNode *root = generate(n);
    show_preorder(root);
    cout << endl;
    int start = clock();
    printNodeAtLevel(root,n-1);
    cout << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    printNodeByLevel1(root,n);
    cout << "time: " << clock()-start << endl;
    start = clock();
    printNodeByLevel2(root);
    cout << "time: " << clock()-start << endl;
    start = clock();
    printNodeByLevel3(root);
    cout << "time: " << clock()-start << endl;
    return 0;
}

