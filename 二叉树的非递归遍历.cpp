//��rootָ��һ�÷ǿն��������ڶ������в��ҹؼ���Ϊkey�Ľ�㣬
//�����ص�ַ����δ�ҵ�����null����ÿ�����������ֵ���ظ�
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
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("����������Ԫ�أ�");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("������keyֵ��");
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


//���б�����������ÿ����㣨�ǵݹ飩
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
	BTNode **Q,*p;//����ָ��洢ָ��Ķ��е�ָ��
	int front=0,rear=0;//ͷָ���βָ�� 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//���пռ䲻Ϊѭ�����У�Ҫ�����ܴ�
	 Q[++rear]=root;
	 while(front!=rear){//���в��գ�ִ�г��ӣ��������Ӳ��� 
	 	p=Q[++front];//���� 
	 	printf("%5d",p->data);//���
	 	if(p->left){
		Q[++rear]=p->left;//����Ů��� 
		}
		if(p->right){
		Q[++rear]=p->right;//����Ů��� 
		}
	 }
}
int main()
{	
	int *a;
	int n,key;
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("����������Ԫ�أ�");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//�������������� 
	LevelOrder(root);//�������Ĳ�α��� 
	return 0;
}*/

 
 //�ǵݹ�ǰ�����
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
	BTNode **Q,*p;//����ָ��洢ָ���ջ��ָ��
	int top=-1;//ջ��ָ�� 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//����ջ�ռ� 
	 Q[++top]=root;
	 while(top!=-1){//ջ���� 
	 	p=Q[top--];//��ջ 
	 	printf("%5d",p->data);//��� 
	 	if(p->right){//����Ů��ջ 
	 		Q[++top]=p->right;
	 	}
	 	if(p->left){//����Ů��ջ 
	 		Q[++top]=p->left;
	 	}
	 }
}
int main()
{	
	int *a;
	int n,key;
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("����������Ԫ�أ�");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//�������������� 
	PreOrder(root);//�������Ĳ�α��� 
	return 0;
}*/



//�ǵݹ��������
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
	BTNode **Q,*p;//����ָ��洢ָ��Ķ��е�ָ��
	int top=-1;//ͷָ���βָ�� 
	Q=(BTNode **)malloc(sizeof(BTNode *)*1000);//���пռ䲻Ϊѭ�����У�Ҫ�����ܴ�
	p=root;
	while(p){
		Q[++top]=p;
		p=p->left;
	} 
	 while(top!=-1){//ջ���� 
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
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("����������Ԫ�أ�");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateBiTree(a,n);//�������������� 
	InOrder(root);//�������Ĳ�α��� 
	return 0;
}*/

//�ǵݹ�������
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
	stack=(ElemSN **)malloc(sizeof(ElemSN *)*1000);//����ջ�ռ� 
	int top=-1;//ջ��ָ��
	while(root||top!=-1){//����㲻����ջ���� 
		while(root){//��������ѹջ 
			stack[++top]=root;
			root=root->left;
		}
		if(top!=-1){//ջ���� 
			root=stack[top];//��ջ 
			if(root->right==NULL||root->right==p){//���Һ��ӻ����к����Ѿ����ʹ� 
				printf("%4d",root->data);
				top--;
				p=root;
				root=NULL;//�����ظ���ջ 
			}
			else{//���Һ��ӣ���δ�����ʹ� 
				root=root->right;
			}
		}
	} 
}*/
void ProBiTree(ElemSN *root)
{
	ElemSN **stack,*p=NULL;
	stack=(ElemSN **)malloc(sizeof(ElemSN *)*1000);//����ջ�ռ� 
	int top=-1;//ջ��ָ��
	while(root||top!=-1){//����㲻����ջ���� 
		if(root){//��������ѹջ 
			stack[++top]=root;
			root=root->left;
		}
		else{//ջ���� 
			root=stack[top];//��ջ 
			if(root->right==NULL||root->right==p){//���Һ��ӻ����к����Ѿ����ʹ� 
				printf("%4d",root->data);
				top--;
				p=root;
				root=NULL;//�����ظ���ջ 
			}
			else{//���Һ��ӣ���δ�����ʹ� 
				root=root->right;
			}
		}
	} 
}
int main()
{
	int n;
	int *a;
	printf("���������鳤��:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ElemSN *root=CreateBiTree(a,n);
	ProBiTree(root);
	return 0;
} 




 
