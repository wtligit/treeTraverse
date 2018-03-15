#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	void levelOrder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			cout << cur->val << " ";
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
	}
	void preOrder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		cout << root->val << " ";
		if (root->left) {
			preOrder(root->left);
		}
		if (root->right) {
			preOrder(root->right);
		}
	}
	void inOrder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		if (root->left) {
			inOrder(root->left);
		}
		cout << root->val << " ";
		if (root->right) {
			inOrder(root->right);
		}
	}
	void postOrder(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		if (root->left) {
			postOrder(root->left);
		}
		if (root->right) {
			postOrder(root->right);
		}
		cout << root->val << " ";
	}
};
int main() {
	TreeNode* s_arr[6];
	s_arr[0] = new TreeNode(0);
	s_arr[1] = new TreeNode(1);
	s_arr[2] = new TreeNode(2);
	s_arr[3] = new TreeNode(3);
	s_arr[4] = new TreeNode(4);
	s_arr[5] = new TreeNode(5);
	s_arr[0]->left = s_arr[1]; 
	s_arr[0]->right = s_arr[2];
	s_arr[1]->left = s_arr[3]; 
	s_arr[3]->left = s_arr[4]; 
	s_arr[2]->right = s_arr[5];
	Solution s;
	s.levelOrder(s_arr[0]);
	cout << endl;
	s.preOrder(s_arr[0]);
	cout << endl;
	s.inOrder(s_arr[0]);
	cout << endl;
	s.postOrder(s_arr[0]);
	cout << endl;
    	for (int i = 0; i < 6; i++)
        	delete s_arr[i];
	return 0;
}
