#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s{
	NODE left;
	NODE right;
	int key;
	void *data;
	int height;
} NODE_t[1];

typedef struct{
	NODE root;
} BST_t[1], *BST;

void print(NODE n, int h){
	int i;
	if(n != NULL){
		print(n->right,h+1);
		for(i = 0; i < h; i++) {
			printf("     ");
		}
		printf("%d\n", n->key);
		print(n->left, h+1);
	}
}

NODE bst_init_node(int key, void *data){
	NODE n = (NODE)malloc(sizeof(NODE_t));
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	n->data = data;
	n->height = 1;
	return n;
}

int calcheight(NODE node){
	if(node==NULL)
		return 0;
	else
		return node->height;
}

int maxheight(int a, int b){
	if(a<b)
		return b;
	else if(b<a)
		return a;
	else	
		return a;
}

int balancefac(NODE node){
	if(node==NULL)
		return 0;
	return calcheight(node->left) - calcheight(node->right);
}

NODE rightRotateAvl(NODE node){
	NODE parent = node->left;  
    NODE child = parent->right;  
     
    parent->right = node;  
    node->left = child;  
   
    node->height = maxheight(calcheight(node->left),  calcheight(node->right)) + 1;  
    parent->height = maxheight(calcheight(parent->left),  calcheight(parent->right)) + 1;  
   
    return parent;  
}

NODE leftRotateAvl(NODE node){
	NODE parent = node->right;  
    NODE child = parent->left;  
     
    parent->left = node;  
    node->right = child;  
  
    node->height = maxheight(calcheight(node->left),  calcheight(node->right)) + 1;  
    parent->height = maxheight(calcheight(parent->left),  calcheight(parent->right)) + 1;  
   
    return parent;  
}

NODE avlsearch(NODE node, int key, void *data){
    if (node == NULL){
		printf("ERROR. This node isn't in the tree.\n\n");
        return node;
	}

    else if (node->key == key){
		printf("Node is in the tree.\n\n");
        return node;
	}	
 
    else if (node->key > key) {
        return avlsearch(node->left, key, data);
    }
 
    else {
        return avlsearch(node->right, key, data);
    }
}


NODE bst_insert_rec_avl(NODE node, int key, void *data){
	if(node == NULL){
		node = bst_init_node(key, data);
	}

	else{
		if(key < node->key){
			node->left = bst_insert_rec_avl(node->left, key, data);
		}
		else if(key > node->key){
			node->right = bst_insert_rec_avl(node->right, key, data);
		}
		else {
			printf("ERROR: Duplicate key: %d. Ignoring...\n\n", key);
		}
		node->height=(maxheight(calcheight(node->left), calcheight(node->right)) + 1);

		int balance = balancefac(node);

		if(balance==2){
			if(calcheight(node->left->left) > calcheight(node->left->right)){
				node = rightRotateAvl(node);
			}
			else{
				node->left = leftRotateAvl(node->left);
				node = rightRotateAvl(node);
			}
		}

		else if(balance==-2){
			if(calcheight(node->right->right) > calcheight(node->right->left)){
				node = leftRotateAvl(node);
			}
			else{
				node->right= rightRotateAvl(node->right);
				node = leftRotateAvl(node);
			}
		}

	}
	
	return node;
}

void bst_insert(BST t, int key, void *data){
	if(t == NULL)
		printf("ERROR. Uninitialized tree\n");
	else{
		if(t->root == NULL){
			t->root = bst_init_node(key, data);
		}
		else{
			t->root = bst_insert_rec_avl(t->root, key, data);
		}
	}
}

NODE lchild(NODE node){
    while (node && node->left != NULL)
        node = node->left;
 
    return node;
}

NODE bst_delete_avl(NODE node, int key, void *data){
	if(node == NULL){
		return node;
	}

	else{
		if(key < node->key){
			node->left = bst_delete_avl(node->left, key, data);
		}
		else if(key > node->key){
			node->right = bst_delete_avl(node->right, key, data);
		}
		else{
			if(node->left == NULL){
				NODE temp=node->right;
				free(node);
				return temp;
			}
			else if(node->right == NULL ){
				NODE temp=node->left;
				free(node);
				return temp;
			}
			//two child
			NODE temp=lchild(node->right);
			node->key=temp->key;
			node->right=bst_delete_avl(node->right, temp->key, data);
		}


		node->height=(maxheight(calcheight(node->left), calcheight(node->right)) + 1);
		int balance = balancefac(node);

		if(balance==2){
			if(calcheight(node->left->left) > calcheight(node->left->right)){
				node = rightRotateAvl(node);
			}
			else{
				node->left = leftRotateAvl(node->left);
				node = rightRotateAvl(node);
			}
		}

		else if(balance==-2){
			if(calcheight(node->right->right) > calcheight(node->right->left)){
				node = leftRotateAvl(node);
			}
			else{
				node->right= rightRotateAvl(node->right);
				node = leftRotateAvl(node);
			}
		}
	}

	return node;
}


BST bst_init(){
	BST t1 = (BST)malloc(sizeof(BST_t));
	t1->root = NULL;
	return t1;
}

void bst_free(BST t){
	//Tentative
	free(t);
}


int main() {
	BST t1 = bst_init();

	bst_insert(t1, 44, NULL);
	bst_insert(t1, 11, NULL);
	bst_insert(t1, 34, NULL);
	bst_insert(t1, 52, NULL);
	bst_insert(t1, 89, NULL);
	bst_insert(t1, 62, NULL);
	bst_insert(t1, 23, NULL);
	bst_insert(t1, 72, NULL);
	bst_insert(t1, 93, NULL);
	bst_insert(t1, 27, NULL);
	bst_insert(t1, 61, NULL);
	bst_insert(t1, 35, NULL);
	bst_insert(t1, 86, NULL);
	

	avlsearch(t1->root,10,NULL);

	printf("AVL Tree:\n");
	print(t1->root,0);

	printf("\n\n After Deletion:\n");

	bst_delete_avl(t1->root, 72, NULL);
	print(t1->root,0);

	bst_free(t1);


	return 0;
}







