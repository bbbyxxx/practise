#include<bits/stdc++.h>

typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;

BTNode *CreateFullBiTree(int a[],int n)//������ȫ������ 
{
	BTNode *root,*p,*pa;
	BTNode **Q;//���մ�ŵ�ַ���еĵ�ַ 
	int front,rear;//���ף���βָ�� 
	Q=(BTNode **)malloc((n+2)*sizeof(BTNode *));//������пռ�,�����ܴ� 
	front=rear=0;
	//���������
	pa=root=(BTNode *)malloc(sizeof(BTNode)); 
	root->data=a[0];
	root->left=root->right=NULL;
	for(int i=1;i<n;i++){//����������� 
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=a[i];
		p->right=p->left=NULL;
		if(!pa->left){
			pa->left=p;
		}
		else{//˵�������������������������Թ���������ָ��˫�׻��ߵ��׵�ָ�����ָ���µ�˫�׻��� 
			pa->right=p;
			pa=Q[++front];
		}
		Q[++rear]=p;
	}
	free(Q);//�ͷŶ�̬������ڴ� 
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

//������С�����ѣ���˫��֧�򵥷�֧��㣩
//�洢--����
void HeapSort(BTNode *root,int n)//������ 
{
	BTNode *p,*pmin;//pminָ����Сֵ��� 
	int t,end;//t����ʱ�洢ֵ    end���洢���ڣ�������� 
	int tag;//�������ѭ��  
	//��ʼ������
	BTNode **Q;
	int front,rear;
	Q=(BTNode **)malloc((n+2)*sizeof(BTNode *));//ͬ��
	front=rear=0;
	//����ȫ����������Ķ���
	Q[++rear]=root;//�����
	while(1){//���������� 
		p=Q[++front];//p���ճ���Ԫ��
		if(!p->left&&!p->right){//p������������Ϊ�գ�����ѭ�� 
			break;
		}
		else{
			if(p->left){
				Q[++rear]=p->left;//p->left��� 
			}
			if(p->right){
				Q[++rear]=p->right;//p->right��� 
			}
		} 
	}
	end=rear;//���ڣ�����������
	//������
	while(front>1){//1~front-1����Ӧָ��Ľ��Ϊ˫�׻��ߵ��׽�� 
		//������
		while(1){
			tag=1;
			for(int k=front-1;k>0;k--){
				p=Q[k];//p���ճ���Ԫ��
				//�ҳ���Сֵ��pmin
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
		//�������������һ��Ҷ��
		 t=root->data;
		 root->data=Q[rear]->data;
		 Q[rear]->data=t;
		 //�������һ��Ҷ��
		 if(Q[front-1]->right){//����Ů���� 
		 	Q[front-1]->right=NULL;
		 }
		 else{
		 	Q[front-1]->left=NULL;
			front--;//˫�׽������Ҷ�ӽ�㣬����frontҪ������	
		} 
		 	rear--;//Ҷ�ӽ�������� 
	} 	 
	//���
	for(;end;end--){
		printf("%5d",Q[end]->data);
	} 
} 

int main()
{
	int n;
	printf("���������鳤��n��");
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	printf("����������Ԫ�أ�");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	BTNode *root=CreateFullBiTree(a,n);//������ȫ���������������н���ַ��� 
	//Print(root);//������ȫ�������Ƿ񴴽���ȷ 
	HeapSort(root,n);//������ 
	return 0;
}
