#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> pre_vector;
vector<int> post_vector;

class NODE {
public:
	int val;
	int num;
	NODE* left;
	NODE* right;
	NODE(int a) : val(a), left(NULL), right(NULL) {}
	NODE(int _val, int _num) : val(_val), num(_num), left(NULL), right(NULL) {}
};

class TREE {
public:
	NODE* root;
	TREE() : root(NULL) {}
	void recursive_insert(NODE*&, int, int);
	void insert(int, int);
	void recursive_pre(NODE*);
	void pre();
	void recursive_post(NODE*);
	void post();
};
void TREE::recursive_insert(NODE*& node, int val, int num) {
	if (node == NULL)
		node = new NODE(val, num);
	else if (val > node->val)
		recursive_insert(node->right, val, num);
	else if (val < node->val)
		recursive_insert(node->left, val, num);
}
void TREE::insert(int val, int num) {
	recursive_insert(root, val, num);
}
void TREE::recursive_pre(NODE* node) {
	if (node != NULL) {
		cout << node->num << " ";
		pre_vector.push_back(node->num);
		recursive_pre(node->left);
		recursive_pre(node->right);
	}
}
void TREE::pre() {
	recursive_pre(root);
}
void TREE::recursive_post(NODE* node) {
	if (node != NULL) {
		recursive_post(node->left);
		recursive_post(node->right);
		cout << node->num << " ";
		post_vector.push_back(node->num);
	}
}
void TREE::post() {
	recursive_post(root);
}

bool comp(vector<int>a, vector<int>b) {
	int ax = a[0];
	int ay = a[1];
	int bx = b[0];
	int by = b[1];
	return ay > by;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<vector<int>> tmp;
	int number = 0;
	for (int i = 0; i < nodeinfo.size(); i++) {
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];
		number++;
		vector<int>item;
		item.push_back(x);
		item.push_back(y);
		item.push_back(number);
		tmp.push_back(item);
	}
	TREE T;
	sort(tmp.begin(), tmp.end(), comp);
	for (int i = 0; i < tmp.size(); i++) {
		int x = tmp[i][0];
		int y = tmp[i][1];
		int n = tmp[i][2];
		T.insert(x, n);

	}
	T.pre();
	T.post();
	answer.push_back(pre_vector);
	answer.push_back(post_vector);
	return answer;
}