//Debug.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<deque>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include"functions.h"
#include"classes.h"
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		int _size = s.size();
		vector<vector<bool>> t(_size, vector<bool>(_size, false));
		for (int j = 0; j < _size;j++) {
			for (int i = 0; i < _size;i++) {
				if (i + j < _size) {
					if (j == 0) {
						t[i][i + j] = true;
					}
					else if (j < 3) {
						t[i][i + j] = (s[i] == s[i + j]);
					}
					else {
						t[i][i + j] = (s[i] == s[i + j]) && (t[i + 1][i + j - 1]);
					}
				}
			}
		}
		vector<vector<string>> res;
		vector<string> res_sub;
		partition(res, res_sub, t, 0, s);
		return res;
	}
private:
	void partition(vector<vector<string>>& res, vector<string>& res_sub, const vector<vector<bool>>& t, int index, const string& s) {
		if (index == t[0].size()) {
			res.push_back(res_sub);
			return;
		}
		for (int i = index; i < t[0].size(); i++) {
			if (t[index][i]) {
				res_sub.push_back(s.substr(index, i - index + 1));
				partition(res, res_sub, t, i + 1, s);
				res_sub.pop_back();
			}
		}
	}
};


int main()
{
	//vector<int> array = { 1, 0, 3, 0, 1 };
	//vector<int> array1 = { 2, 1, 2, 5, 7, 1, 9, 3 };
	//vector<int> array2 = { 2,1,3 };
	//vector<vector<int>> matrix = {
	//	{},
	//	{1,5,7},
	//	{4},
	//	{ 2,3,5,11},
	//	{ 2,4,4,6,8 }
	//};
	//vector<vector<int>> matrix = {
	//	{1,-3,3},
	//	{0,-2,0},
	//	{-3,-3,-3}
	//};
	//vector<vector<int>> matrix = {
	//	{ 100}
	//};
	//vector<vector<int>> matrix = {
	//	{1,2},
	//	{3,4}
	//};
	//int number = 4;
	//string input = "kekehu memeda leletu";
	string s = "aab";
	//vector<string> words = { "foo", "bar" };

	//string s = "aba";
	//string s1 = "abcde", s2 = "cd";
	//string s1 = "aaa", s2 = "aa", s3 = "";
	//vector<int> tree = { 5,2,11, NULL, NULL, 6, 14 };

	//TreeNodeP *node5 = new TreeNodeP(5, NULL);
	//TreeNodeP *node9 = new TreeNodeP(9, node5);
	//TreeNodeP *node12 = new TreeNodeP(12, node5);
	//TreeNodeP *node2 = new TreeNodeP(2, node9);
	//TreeNodeP *node3 = new TreeNodeP(3, node9);
	//TreeNodeP *node14 = new TreeNodeP(14, node12);
	//TreeNodeP *node8 = new TreeNodeP(8, NULL);
	//node5->left = node9;
	//node5->right = node12;
	//node9->left = node2;
	//node9->right = node3;
	//node12->right = node14;

	//stack<int> s1, s2;
	//s1.push(1);
	//s1.push(3);
	//s1.push(2);
	//s1.push(4);
	//s1.push(8);
	//s1.push(8);
	//s1.push(2);
	//s1.push(5);
	//s1.push(7);
	//TreeNode* root = buildTree(tree);
	//printTree(root);
	Solution a;
	show(a.partition(s));
	//printTree(root);


	//a.solve(2);
	//a.sortByStack(s1, s2);
	//show(matrix);
	//a.read(1);
	//a.read(2);
	//a.read(3);
	//cout << a.median();
	//int i = -1;
	//unsigned int j = i;

	//cout << i << endl << j;
	//j = 0u;
	//j--;
	//cout << j;
	return 0;
}