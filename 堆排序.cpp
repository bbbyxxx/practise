#include<bits/stdc++.h>

typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;

BTNode *CreateFullBiTree(int a[],int n)//创建完全二叉树 
{
	BTNode *root,*p,*pa;
	BTNode **Q;//接收存放地址队列的地址 
	int front,rear;//队首，队尾指针 
	Q=(BTNode **)malloc((n+2)*sizeof(BTNode *));//申请队列空间,尽可能大 
	front=rear=0;
	//创建根结点
	pa=root=(BTNode *)malloc(sizeof(BTNode)); 
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){//创建其他结点 
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->right=p->left=NULL;
		if(!pa->left){
			pa->left=p;
		}
		else{//说明有左子树，无右子树，所以挂右子树，指向双亲或者单亲的指针后移指向新的双亲或单亲 
			pa->right=p;
			pa=Q[++front];
		}
		Q[++rear]=p;
	}
	free(Q);//释放动态分配的内存 
	return root;
}

/*void Print(BTNode *root)
{
	if(root){
	printf("%4d",root->data);
	Print(root->left);
	Print(root->right);
	}
}*/

//调整大（小）根堆（找双分支或单分支结点）
//存储--队列
void HeapSort(BTNode *root,int n)//堆排序 
{
	BTNode *p,*pmin;//pmin指向最小值结点 
	int t,end;//t：临时存储值    end：存储岗哨，用于输出 
	int tag;//标记跳出循环  
	//初始化队列
	BTNode **Q;
	int front,rear;
	Q=(BTNode **)malloc((n+2)*sizeof(BTNode *));//同上
	front=rear=0;
	//将完全二叉树放入的队列
	Q[++rear]=root;//根入队
	while(1){//其他结点入队 
		p=Q[++front];//p接收出队元素
		if(!p->left&&!p->right){//p的左右子树都为空，跳出循环 
			break;
		}
		else{
			if(p->left){
				Q[++rear]=p->left;//p->left入队 
			}
			if(p->right){
				Q[++rear]=p->right;//p->right入队 
			}
		} 
	}
	end=rear;//岗哨，用于最后输出
	//堆排序
	while(front>1){//1~front-1所对应指向的结点为双亲或者单亲结点 
		//调整堆
		while(1){
			tag=1;
			for(int k=front-1;k>0;k--){
				p=Q[k];//p接收出队元素
				//找出最小值给pmin
				pmin=p;
				if(p->data>p->left->data){
					pmin=p->left;
				}
				if(p->right){
					if(pmin->data>p->right->data){
						pmin=p->right;
					}
				}
				if(p!=pmin){
					t=p->data;
					p->data=pmin->data;
					pmin->data=t;
					tag=0;;
				}
			}//for
			if(tag==1){
				break;
			}
		}//while(1) 
		//交换根结点和最后一个叶子
		 t=root->data;
		 root->data=Q[rear]->data;
		 Q[rear]->data=t;
		 //砍掉最后一个叶子
		 if(Q[front-1]->right){//右子女不空 
		 	Q[front-1]->right=NULL;
		 }
		 else{
		 	Q[front-1]->left=NULL;
			front--;//双亲结点变成了叶子结点，所以front要往回缩	
		} 
		 	rear--;//叶子结点往回缩 
	} 	 
	//输出
	for(;end;end--){
		printf("%5d",Q[end]->data);
	} 
} 

int main()
{
	int n;
	printf("请输入数组长度n：");
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	printf("请输入数组元素：");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateFullBiTree(a,n);//创建完全二叉树，并将所有结点地址入队 
	//Print(root);//测试完全二叉树是否创建正确 
	HeapSort(root,n);//堆排序 
	return 0;
}
