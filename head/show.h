#include<vector>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<unordered_map>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


void show(vector<int>& nums) {
    for(int i = 0;i < nums.size();i++)
	cout << nums[i] << "\t";
    cout << endl;
}

void show(vector<vector<int>>& nums) {
    for(int i = 0;i < nums.size();i++) {
	for(int j = 0;j < nums[i].size();j++) 
	    cout << nums[i][j] << "\t";
	cout << endl;
    }
}

void show(vector<string>& nums) {
    for(int i = 0;i < nums.size();i++)
	cout << nums[i] << endl;
}

void show(ListNode* l) {
    while(l) {
	cout << l->val << "\t";
	l = l->next;
    }
    cout << endl;
}

void show_preorder(TreeNode* t) {
    if(t) {
	cout << t->val << "\t";
	show_preorder(t->left);
	show_preorder(t->right);
    }
}

void show_inorder(TreeNode* t) {
    if(t) {
	show_inorder(t->left);
	cout << t->val << "\t";
	show_inorder(t->right);
    }
}

void show_postorder(TreeNode* t) {
    if(t) {
	show_postorder(t->left);
	show_postorder(t->right);
	cout << t->val << "\t";
    }
}
