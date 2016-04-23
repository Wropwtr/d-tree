/*struct Node {
	int key;
	Node *left;
	Node *right;
	Node *parent;
	TData *data;
};

class tree{
	Node *root;

};

void single_right_insert(Node *&A){
	Node *B, *t1, *t2, *t3;
	B = A->left;
	t1 = B->left;
	t2 = B->right;
	t3 = A->right;
	A->left = t2;
	B->right = A;
	A->parent = B;
	t2->parent = A;
	A = B;
}

void single_left_insert(Node *&A){
	Node *B, *t1, *t2, *t3;
	B = A->right;
	t1 = A->left;
	t2 = B->left;
	t3 = B->right;
	A->right = t2;
	B->left = A;
	A->parent = B;
	t2->parent = A;
	A = B;
}

void double_right_insert(Node *&A){
	Node *B, *C, *t1, *t2, *t3, *t4;
	B = A->left;
	t1 = B->left;
	C = B->right;
	t2 = C->left;
	t3 = C->right;
	t4 = A->right;

	C->right = A;
	C->left = B;
	B->right = t2;
	B->left = t1;
	A->right = t4;
	A->left = t3;
	A->parent = C;
	t2->parent = B;
	B->parent = C;
	t3->parent = A;
	A = C;
}

void double_left_insert(Node *&A){
	Node *B, *C, *t1, *t2, *t3, *t4;
	B = A->right;
	t1 = A->left;
	C = B->left;
	t2 = C->left;
	t3 = C->right;
	t4 = B->right;

	C->right = B;
	C->left = A;
	B->left = t3;
	A->right = t2;
	A->left = t1;
	A->parent = C;
	t2->parent = A;
	B->parent = C;
	t3->parent = B;
	A = C;
}

void single_right_delete(Node *&A){
	Node *B, *t1, *t2, *t3;
	B = A->right;
	t1 = A->left;
	t2 = B->left;
	t3 = B->right;

	A->right = t2;
	B->left = A;
	A->parent = B;
	t2->parent = A;
	A = B;
}

void single_left_delete(Node *&A){
	Node *B, *t1, *t2, *t3;
	B = A->left;
	t3 = A->right;
	t1 = B->left;
	t2 = B->right;
	
	A->left = t2;
	B->right = A;
	A->parent = B;
	t2->parent = A;
	A = B;
}
*/