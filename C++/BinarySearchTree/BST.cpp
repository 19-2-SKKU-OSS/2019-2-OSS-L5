//Write the following functions:
//(a) PrintPreorder(root)
//(b) Insert(n, root)
//(c) Delete(n, root) ← Use Inorder Successor
//(d) Balance(root) ← Convert a normal BST to a balanced BST
//(e) root = Merge(root1, root2) ← Merge two balanced BSTs and return a new root.

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef int Key;

typedef struct node {
	Key key;
	struct node *l, *r;
}Node;

Node *createNode(int n) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->key = n;
	newNode->l = newNode->r = NULL;
	return newNode;
}

void PrintPreorder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->key);
	PrintPreorder(root->l);
	PrintPreorder(root->r);
}

int countNodes(Node* root)
{
	int count = 1;    

	if (root == NULL) return 0;
	else{
		count += countNodes(root->l);
		count += countNodes(root->r);
		return count;
	}
}

Node* Insert(int n, Node* root) {
	if (root == NULL)  return createNode(n);

	if (n < root->key) {
		root->l = Insert(n, root->l);
	}
	else if (n > root->key) {
		root->r = Insert(n, root->r);
	}

	return root;
}

Node* Delete(int n, Node* root) {
	if (root == NULL) return root;

	if (n < root->key) {
		root->l = Delete(n, root->l);
	}
	else if (n > root->key) {
		root->r = Delete(n, root->r);
	}

	else {
		if (root->l == NULL) {
			Node *newrootr = root->r;
			free(root);
			return newrootr;
		}
		else if (root->r == NULL) {
			Node *newrootl = root->l;
			free(root);
			return newrootl;
		}

		Node* temp = root->r;
		while (temp&&temp->l != NULL) {
			temp = temp->l;
		}

		root->key = temp->key;
		root->r = Delete(temp->key, root->r);
	}
	return root;
}

void storeNodes(Node* root, vector<Node*> &nodes) {
	if (root == NULL) return;

	storeNodes(root->l, nodes);
	nodes.push_back(root);
	storeNodes(root->r, nodes);
}

Node* buildTree(vector<Node*> &nodes, int start, int end) {
	if (start > end)return NULL;

	int mid = (start + end) / 2;
	Node *newroot = nodes[mid];

	newroot->l = buildTree(nodes, start, mid - 1);
	newroot->r = buildTree(nodes, mid + 1, end);

	return newroot;
}

Node* Balance(Node* root) {
	vector<Node *> nodes;
	storeNodes(root, nodes);
	int n = nodes.size();

	return buildTree(nodes, 0, n - 1);
}

int *merge(int arr1[], int arr2[], int m, int n) {
	int *newArr = new int[m + n];
	int i = 0, j = 0, k = 0;

	while (i < m && j < n){  
		if (arr1[i] < arr2[j]){
			newArr[k] = arr1[i];
			i++;
		}
		else{
			newArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < m){
		newArr[k] = arr1[i];
		i++; 
		k++;
	}

	while (j < n){
		newArr[k] = arr2[j];
		j++; 
		k++;
	}

	return newArr;
}

void storeInorder(node* root, int inorder[], int *index_ptr) {
	if (root == NULL) return;

	storeInorder(root->l, inorder, index_ptr);
	inorder[*index_ptr] = root->key;
	(*index_ptr)++;  
	storeInorder(root->r, inorder, index_ptr);
}

Node* sortedArrToBST(int arr[], int start, int end){
	if (start > end) return NULL;

	int mid = (start + end) / 2;
	node *newroot = createNode(arr[mid]);

	newroot->l = sortedArrToBST(arr, start, mid - 1);
	newroot->r = sortedArrToBST(arr, mid + 1, end);

	return newroot;
}

Node* Merge(Node* root1, Node* root2) {
	int m = countNodes(root1);
	int n = countNodes(root2);

	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	int *newArr = merge(arr1, arr2, m, n);

	return sortedArrToBST(newArr, 0, m + n - 1);
}

int main() {
	Node* root=NULL;
	Node* root1=NULL;
	Node* root2=NULL;

	root1 = Insert(30, root1); root1 = Insert(20, root1); root1 = Insert(50, root1);
	root1 = Insert(10, root1); root1 = Insert(80, root1); root1 = Insert(40, root1);
	root1 = Insert(70, root1);
	PrintPreorder(root1);
	printf("\n");

	root1 = Delete(70, root1); root1 = Delete(20, root1); root1 = Delete(50, root1);
	PrintPreorder(root1);
	printf("\n");

	root1 = Insert(70, root1); root1 = Insert(20, root1);
	PrintPreorder(root1);
	printf("\n");

	root1 = Balance(root1);
	PrintPreorder(root1);
	printf("\n");

	root2 = Insert(50, root2); root2 = Insert(60, root2); root2 = Insert(90, root2);
	PrintPreorder(root2);
	printf("\n");

	root2 = Balance(root2);
	PrintPreorder(root2);
	printf("\n");
	
	root = Merge(root1, root2);
	PrintPreorder(root);
	
}
