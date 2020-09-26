#include<iostream>

using namespace std;



class BinaryTree
{
protected:
	struct Node {
		int    data;
		Node* left;
		Node* right;
		Node() : data(), left(NULL), right(NULL) { }
	};
private:
	Node* _root = NULL;
public:
	void CreateTree(int myArray[]);
	void CreateBranch(Node* parent, int data);
	void Search(int data, int myArray[]);
	void DestroyTree();
	void DestroyBranch(Node* branchToCut);
};

void BinaryTree::CreateTree(int myArray[]) {
	
	for (int i = 0; i < 100; i++)
	{
		if (_root == NULL) {
			_root = new Node();
			_root->data = myArray[i];
		}
		else{
			this->CreateBranch(_root , myArray[i]);
		}
	}
	cout << "Tree Creation Successful!\n\n";
}

void BinaryTree::CreateBranch(Node* parent, int data) {

	if (data > parent->data) {
		if (parent->right == NULL) {
			parent->right = new Node();
			parent->right->data = data;
			return;
		}
		else
		{
			CreateBranch(parent->right, data);
		}
	}
	else if(data < parent->data){
		if (parent->left == NULL) {
			parent->left = new Node();
			parent->left->data = data;
			return;
		}
		else
		{
			CreateBranch(parent->left, data);
		}
	}
	else
	{
		cout << "Error creating Tree, " << data << " might be a duplicate number!\n\n";
		return;
	}

}

void BinaryTree::Search(int data, int myArray[]) {

	Node* curr = _root;
	int countArray = 0;
	int countTree = 0;

	if (curr == NULL) {
		cout << data << " was NOT found in Tree due to Tree being Null\n";
	}
	else{
		while (true) {
			countTree++;
			if (curr == NULL) {
				cout << data << " was NOT found in Tree after " << countTree << " comparisons\n";
				break;
			}
			else if (data == curr->data) {
				cout << data << " was found in Tree after " << countTree << " comparisons\n";
				break;
			}
			else {
				if (data < curr->data) {
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		countArray++;
		if (myArray[i] != data) {
			continue;
		}
		else {
			if (myArray[i] == data) {
				cout << data << " was found in array after " << countArray << " comparisons\n";
			}
			else {
				cout << data << " was NOT found in array after " << countArray << " comparisons\n";
			}
			break;
		}
	}
	cout << "\n";
}

void BinaryTree::DestroyTree() {

	Node* branchToCut = _root;

	if(branchToCut == NULL){
		return;
	}
	else {
		DestroyBranch(branchToCut);
	}
}

void BinaryTree::DestroyBranch(Node* branchToCut) {

	if (branchToCut == NULL) {
		return;
	}

	if (branchToCut->left == NULL && branchToCut->right == NULL) {
		delete(branchToCut);
		branchToCut = NULL;
	}
	else {
		if (branchToCut->left != NULL) {
			DestroyBranch(branchToCut->left);
		}
		if (branchToCut->right != NULL) {
			DestroyBranch(branchToCut->right);
		}
	}
	return;
}
