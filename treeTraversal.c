#include<stdio.h>
#include<stdlib.h>

//structure of each node of tree
struct node{
	char data;
	struct node *left; //left child 
	struct node *right; // right child
	};

//declaring functions before using them 	
void preorderTraversal(struct node *t);
struct node * createTree();
void inorderTraversal(struct node *t);
void postorderTraversal(struct node *t);
int numberOfNodes(struct node *t);
int numberOfLeafNodes(struct node *t);
int numberOfNonLeafNodes(struct node *t);
int numberOfFullNodes(struct node *t);
int heightOfTree(struct node *t);
int isComplete(struct node *t);

struct node * createNode(){
		
	struct node *p = (struct node *) malloc(sizeof(struct node));
		p->data = NULL;
		p->left = NULL;
		p->right = NULL;	
		
		return p;
		
	}

void main(){
	
	
	struct node *t = createTree();
	printf("\nPreorder traversal : ");
	preorderTraversal(t);
	
	
	printf("\nPostorder traversal : ");
	postorderTraversal(t);
	
	printf("\ninorder traversal : ");
	inorderTraversal(t);
		
	printf("\nnumber of nodes : %d \n",numberOfNodes(t));
	
	printf("\nnumber of leaf nodes : %d \n",numberOfLeafNodes(t));
		
	printf("\nnumber of non leaf nodes : %d \n",numberOfNonLeafNodes(t));
	
	printf("\nnumber of full nodes : %d \n",numberOfFullNodes(t));
	
	printf("\nHeight of tree : %d \n",heightOfTree(t));
	
	printf("\ncomplete tree : %d \n",isComplete(t));
	
	
	}
	
int isComplete(struct node *t){

	if(!t)return 1;
	if(!t->left && !t->right){
		
		return 1;
		}	
	else if(t->left && t-> right){
		
		return (isComplete(t->left) && isComplete(t->right));
		}
		else{
			return 0;
			}
	
	}	

int numberOfFullNodes(struct node *t){
	//full node - > node with both left and right child
	if(!t){return 0;}
	if(!t->left && !t->right){
		return 0;
		}
	if(t->left && t->right){
		return(1 + numberOfFullNodes(t->left)+numberOfFullNodes(t->right));
		}	
	else{
		return(numberOfFullNodes(t->left)+numberOfFullNodes(t->right));
		
		}	
	}
	
	
int heightOfTree(struct node *t){
	if(!t){return 0;}
	if(!t->left && !t->right){ //leaf , so height = 0 
		return 0;
		}
	int leftHeight , rightHeight;
	leftHeight = heightOfTree(t->left); //height of left sub tree
	rightHeight = heightOfTree(t->right); //hieght of right sub tree
	return (1 + ((leftHeight>rightHeight)?leftHeight:rightHeight));	// max of height of left and right tree
	}

	
int numberOfNonLeafNodes(struct node *t){
		if(!t){return 0;}
	if(!t->left && !t->right){ //leaf node
		return (0);
		}
	else{ //non leaf
		return(1+numberOfNonLeafNodes(t->left)+numberOfNonLeafNodes(t->right));
		}	
	
	}	


int numberOfLeafNodes(struct node *t){
	if(!t){return 0;}
	if(!t->left && !t->right){ //leaf node
		return (1);
		}
	else{ //non leaf
		return(numberOfLeafNodes(t->left)+numberOfLeafNodes(t->right));
		}	
	}	
	
	
int numberOfNodes(struct node *t){
	if(!t)return 0;
	if(!t->left && !t->right){ // if left & right child are null , it is a leaf node so return 1
		return (1);
		}
		else{ // it is not a leaf node so return 1 + number of nodes on the left subtree + number of nodes on the right sub tree
			return (1+numberOfNodes(t->left)+numberOfNodes(t->right));
			}
	}	
	
	
void inorderTraversal(struct node *t){
	if(t==NULL)return;
	
	inorderTraversal(t->left);
	printf("%c",t->data);
	inorderTraversal(t->right);
	
		
	}		


void postorderTraversal(struct node *t){
	if(t==NULL)return;
	
	postorderTraversal(t->left);
	postorderTraversal(t->right);
	printf("%c",t->data);
	
	}	


void preorderTraversal(struct node *t){
	if(t==NULL)return;
	printf("%c",t->data);
	preorderTraversal(t->left);
	preorderTraversal(t->right);
	
	}
	
	
struct node * createTree(){
	
	
	char elements[8] = {'b','a','c','d','f','e','g' , 'h'};
	
	struct node *root = createNode();
	struct node *child1 = createNode();
	struct node *child2 = createNode();
		
		root->data = elements[0];
		root->left = child1;
		root->right = child2;	
		
		
	struct node *child11 = createNode();
	struct node *child12 = createNode();
		
		child1->data = elements[1];
		child1->left = child11;
		child1->right = child12;	

		
	struct node *child21 = createNode();
	struct node *child22 = createNode();
		
		child2->data = elements[2];
		child2->left = child21;
		child2->right = child22;	


		
	child11->left = NULL;
	child11->right = NULL;
	child11->data = elements[3];
	
	
	
	child12->left = NULL;
	child12->right = NULL;
	child12->data = elements[4];
		
		
	child21->left = NULL;
	child21->right = NULL;
	child21->data = elements[5];
	
	child22->left = NULL;
	child22->right = NULL;
	child22->data = elements[6];
	
	struct node *child111 = createNode();
		
		child111->data = elements[7];
		child11->left = child111;
		child111->left = NULL;	
		child111->right = NULL;


		
	return root;
	}
