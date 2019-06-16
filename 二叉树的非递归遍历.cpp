//设root指向一棵非空二叉树，在二叉树中查找关键字为key的结点，
//并返回地址，若未找到返回null，设每个结点数据域值不重复
/*#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;
BTNode *CreateBiTree(int a[],int n)
{
	BTNode *root,*c,*p,*q;
	root=(BTNode *)malloc(sizeof(BTNode));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c){
			q=c;
			if(c->data>p->data){
				c=c->left;
			}
			else{
				c=c->right;
			}
		}
		if(q->data>p->data){
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
	return root;
}
BTNode *Findkey(BTNode *r,int key)
{
	BTNode *lr,*rr;
	if(!r)
	{
		return NULL;
	}
		if(r->data==key){
			return r;
		}
		else{
			lr=Findkey(r->left,key);
			rr=Findkey(r->right,key);
			if(lr){
				return lr;
			}
			else if(rr){
				return rr;
			}
			else{
				return NULL;
			}
		}
			
}
int main()
{	
	int *a;
	int n,key;
	printf("请输入数组长度：");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入数组元素：");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入key值：");
	scanf("%d",&key);
	BTNode *root=CreateBiTree(a,n);
	root=Findkey(root,key);
	if(root){
		printf("%d",root->data); 
	}
	else{
		printf("NULL");
	}
	
	return 0;
}*/


//按行遍历二叉树的每个结点（非递归）
/*#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;
BTNode *CreateBiTree(int a[],int n)
{
	BTNode *root,*c,*p,*q;
	root=(BTNode *)malloc(sizeof(BTNode));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c){
			q=c;
			if(c->data>p->data){
				c=c->left;
			}
			else{
				c=c->right;
			}
		}
		if(q->data>p->data){
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
	return root;
}
void LevelOrder(BTNode *root)
{
	BTNode **Q,*p;//声明指向存储指针的队列的指针
	int front=0,rear=0;//头指针和尾指针 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//队列空间不为循环队列，要尽可能大
	 Q[++rear]=root;
	 while(front!=rear){//队列不空，执行出队，输出，入队操作 
	 	p=Q[++front];//出队 
	 	printf("%5d",p->data);//输出
	 	if(p->left){
		Q[++rear]=p->left;//左子女入队 
		}
		if(p->right){
		Q[++rear]=p->right;//右子女入队 
		}
	 }
}
int main()
{	
	int *a;
	int n,key;
	printf("请输入数组长度：");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入数组元素：");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//建立二叉排序树 
	LevelOrder(root);//二叉树的层次遍历 
	return 0;
}*/

 
 //非递归前序遍历
/*#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;
BTNode *CreateBiTree(int a[],int n)
{
	BTNode *root,*c,*p,*q;
	root=(BTNode *)malloc(sizeof(BTNode));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c){
			q=c;
			if(c->data>p->data){
				c=c->left;
			}
			else{
				c=c->right;
			}
		}
		if(q->data>p->data){
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
	return root;
}
void PreOrder(BTNode *root)
{
	BTNode **Q,*p;//声明指向存储指针的栈的指针
	int top=-1;//栈顶指针 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//分配栈空间 
	 Q[++top]=root;
	 while(top!=-1){//栈不空 
	 	p=Q[top--];//出栈 
	 	printf("%5d",p->data);//输出 
	 	if(p->right){//右子女入栈 
	 		Q[++top]=p->right;
	 	}
	 	if(p->left){//左子女入栈 
	 		Q[++top]=p->left;
	 	}
	 }
}
int main()
{	
	int *a;
	int n,key;
	printf("请输入数组长度：");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入数组元素：");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//建立二叉排序树 
	PreOrder(root);//二叉树的层次遍历 
	return 0;
}*/



//非递归中序遍历
/*#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;
BTNode *CreateBiTree(int a[],int n)
{
	BTNode *root,*c,*p,*q;
	root=(BTNode *)malloc(sizeof(BTNode));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c){
			q=c;
			if(c->data>p->data){
				c=c->left;
			}
			else{
				c=c->right;
			}
		}
		if(q->data>p->data){
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
	return root;
}
void InOrder(BTNode *root)
{
	BTNode **Q,*p;//声明指向存储指针的队列的指针
	int top=-1;//头指针和尾指针 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//队列空间不为循环队列，要尽可能大
	p=root;
	while(p){
		Q[++top]=p;
		p=p->left;
	} 
	 while(top!=-1){//栈不空 
	 	p=Q[top--];
	 	printf("%5d",p->data);
	 	if(p->right){
	 		p=p->right;
	 		while(p){
			Q[++top]=p;
			p=p->left;
		} 
	 	}
	 }
}
int main()
{	
	int *a;
	int n,key;
	printf("请输入数组长度：");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("请输入数组元素：");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//建立二叉排序树 
	InOrder(root);//二叉树的层次遍历 
	return 0;
}*/

//非递归后序遍历
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}ElemSN;
ElemSN *CreateBiTree(int a[],int n)
{
	ElemSN *root,*c,*p,*q;
	root=(ElemSN *)malloc(sizeof(ElemSN));
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->left=p->right=NULL;
		c=root;
		while(c){
			q=c;
			if(c->data>p->data){
				c=c->left;
			}
			else{
				c=c->right;
			}
		}
		if(q->data>p->data){
			q->left=p;
		}
		else{
			q->right=p;
		}
	}
	return root;
}
/*void ProBiTree(ElemSN *root)
{
	ElemSN **stack,*p=NULL;
	stack=(ElemSN **)malloc(sizeof(ElemSN *)*1000);//分配栈空间 
	int top=-1;//栈顶指针
	while(root||top!=-1){//根结点不空且栈不空 
		while(root){//将左子树压栈 
			stack[++top]=root;
			root=root->left;
		}
		if(top!=-1){//栈不空 
			root=stack[top];//出栈 
			if(root->right==NULL||root->right==p){//无右孩子或者有孩子已经访问过 
				printf("%4d",root->data);
				top--;
				p=root;
				root=NULL;//避免重复入栈 
			}
			else{//有右孩子，但未被访问过 
				root=root->right;
			}
		}
	} 
}*/
void ProBiTree(ElemSN *root)
{
	ElemSN **stack,*p=NULL;
	stack=(ElemSN **)malloc(sizeof(ElemSN *)*1000);//分配栈空间 
	int top=-1;//栈顶指针
	while(root||top!=-1){//根结点不空且栈不空 
		if(root){//将左子树压栈 
			stack[++top]=root;
			root=root->left;
		}
		else{//栈不空 
			root=stack[top];//出栈 
			if(root->right==NULL||root->right==p){//无右孩子或者有孩子已经访问过 
				printf("%4d",root->data);
				top--;
				p=root;
				root=NULL;//避免重复入栈 
			}
			else{//有右孩子，但未被访问过 
				root=root->right;
			}
		}
	} 
}
int main()
{
	int n;
	int *a;
	printf("请输入数组长度:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ElemSN *root=CreateBiTree(a,n);
	ProBiTree(root);
	return 0;
} 




 
