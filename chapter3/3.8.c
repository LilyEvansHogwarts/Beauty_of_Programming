#include "../head/show.h"

struct Node {
    Node* left;
    Node* right;
    int maxLeft;
    int maxRight;
    char chValue;
    Node(char x):chValue(x),maxLeft(0),maxRight(0),left(NULL),right(NULL) {}
};

int maxLen = 0;

void findMaxLen(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL) root->maxLeft = 0;
    else findMaxLen(root->left);
    if(root->right == NULL) root->maxRight = 0;
    else findMaxLen(root->right);
    if(root->left) 
	root->maxLeft = max(root->left->maxLeft,root->left->maxRight)+1;
    if(root->right) 
	root->maxRight = max(root->right->maxLeft,root->right->maxRight)+1;
    maxLen = max(root->maxLeft + root->maxRight,maxLen);
}

Node* generate_solve(int k,int n) {
    if(k == n) return NULL;
    Node *root = new Node(rand()%26+'a');
    root->left = generate_solve(k+1,n);
    root->right = generate_solve(k+1,n);
    return root;
}

Node* generate(int n) {
    return generate_solve(0,n);
}

void printNode(Node* root) {
    if(root == NULL) return;
    vector<Node*> res(1,root);
    int cur = 0,last = 1;
    while(cur < res.size()) {
	last = res.size();
	while(cur < last) {
	    cout << res[cur]->chValue << "(" << res[cur]->maxLeft << "," << res[cur]->maxRight << ") ";;
	    if(res[cur]->left)
		res.push_back(res[cur]->left);
	    if(res[cur]->right)
		res.push_back(res[cur]->right);
	    cur++;
	}
	cout << endl;
    }
}

int main() {
    int n = 4;
    Node *root = generate(n);
    findMaxLen(root);
    cout << "maxLen: " << maxLen << endl;
    printNode(root);
    return 0;
}

