#include "../head/show.h"

struct Node {
    Node* left;
    Node* right;
    char chValue;
};

void rebuild(char* preorder,char* inorder,int treeLen,Node** root) {
    if(preorder == NULL || inorder == NULL) return;
    Node *temp = new Node;
    temp->left = NULL;
    temp->right = NULL;
    temp->chValue = *preorder;
    if(*root == NULL) *root = temp;
    if(treeLen == 1) return;
    int tempLen = 0;
    char *leftEnd = inorder;
    while(*preorder != *leftEnd) {
	if(preorder == NULL || leftEnd == NULL) return;
	tempLen++;
	if(tempLen > treeLen) break;
	leftEnd++;
    }
    int leftLen = (int)(leftEnd - inorder);
    int rightLen = treeLen-leftLen-1;
    if(leftLen > 0) rebuild(preorder+1,inorder,leftLen,&((*root)->left));
    if(rightLen > 0) rebuild(preorder+leftLen+1,inorder+leftLen+1,rightLen,&((*root)->right));
}

void show(Node* root) {
    if(root) {
	show(root->left);
	show(root->right);
	cout << root->chValue << "\t";
    }
}

int main() {
    Node *root = NULL;
    //char *preorder = "abdhiejkcflmgn"; if not valid, cause it can only be used as const
    //thus,rebuild function should be rebuild(const char*,const char*,int,Node**)
    char preorder[] = "abdhiejkcflmgn";
    char inorder[] = "hdibjekalfmcng";
    int n = 14;
    rebuild(preorder,inorder,n,&root);
    show(root);
    cout << endl;
    return 0;
}
