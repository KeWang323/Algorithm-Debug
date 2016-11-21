#pragma once
#include<vector>
#include"classes.h"
using namespace std;


void show(bool flag) {
	cout << (flag == true) << endl;
}

void show(int number) {
	cout << setw(3) << number;
	cout << endl;
}

void show(const vector<int>& array) {
	for (unsigned int i = 0; i < array.size(); i++) {
		cout << setw(3) << array[i];
	}
	cout << endl;
}

void show(const vector<vector<int>>& matrix) {
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int j = 0; j < matrix[0].size(); j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void show(const string& s) {
	cout << s;
	cout << endl;
}

void show(const vector<string>& array) {
	for (string str : array) {
		cout << str << " ";
	}
	cout << endl;
}

void show(const vector<vector<string>> str) {
	for (int i = 0; i < str.size(); i++) {
			show(str[i]);
	}
}

void show(TreeNode* node) {
	if (node != NULL) {
		cout << node->value << endl;
	}
	else {
		cout << "NULL" << endl;
	}
}

void show(TreeNodeP* node) {
	if (node != NULL) {
		cout << node->value << endl;
	}
	else {
		cout << "NULL" << endl;
	}
}

void show(stack<int> s) {
	cout << "Í·£º ";
	vector<int> t(s.size());
	for (int i = s.size() - 1; i >= 0;i--) {
		t[i] = s.top();
		s.pop();
	}
	show(t);
}

int getTreeHight(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return max(getTreeHight(root->left), getTreeHight(root->right)) + 1;
}

void printTree(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	int i = 1, hight = getTreeHight(root);
	while (i <= hight) {
		int _size = q.size();
		for (int i = 0; i < _size; i++) {
			TreeNode* node = q.front();
			q.pop();
			if (node == NULL) {
				q.push(NULL);
				q.push(NULL);
				cout << "NULL" << " ";
			}
			else {
				cout << node->value << " ";
				if (node->left != NULL) {
					q.push(node->left);
				}
				else {
					q.push(NULL);
				}
				if (node->right != NULL) {
					q.push(node->right);
				}
				else {
					q.push(NULL);
				}
			}
		}
		cout << endl;
		i++;
	}
}

TreeNode* buildTree(vector<int> tree) {
	TreeNode* root = new TreeNode(tree[0]);
	queue<pair<TreeNode*, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<TreeNode*, int> p = q.front();
		q.pop();
		int index = p.second;
		if (index * 2 + 1 < tree.size() && tree[2 * index + 1] != NULL) {
			p.first->left = new TreeNode(tree[index * 2 + 1]);
			q.push(make_pair(p.first->left, index * 2 + 1));
		}
		if (index * 2 + 2 < tree.size() && tree[2 * index + 2] != NULL) {
			p.first->right = new TreeNode(tree[index * 2 + 2]);
			q.push(make_pair(p.first->right, index * 2 + 2));
		}
	}
	return root;
}