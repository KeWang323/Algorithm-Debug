#pragma once
class TreeNode {
public:
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : value(v), left(NULL), right(NULL) {}
};

class TreeNodeP {
public:
	int value;
	TreeNodeP* left;
	TreeNodeP* right;
	TreeNodeP* parent;
	TreeNodeP(int v, TreeNodeP* p)
		: value(v), left(NULL), right(NULL), parent(p) {}
};

class ListNode {
public:
	int value;
	ListNode* next;
	ListNode(int v) : value(v), next(NULL) {}
};

class GraphNode {
public:
	int value;
	vector<GraphNode*> neighbors;
	GraphNode(int v) : value(v) {}
};

class Comp {
public:
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.first > p2.first;
	}
};