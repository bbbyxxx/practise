//������Huffman Tree 

/*#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char word;//���� 
	int weight;//Ȩ�� 
	struct node *left,*right;
}HuffNode;

HuffNode *CreateHuffmanTree(HuffNode **F,int n)
{
	int loop,i,k1,k2;
	HuffNode *pa;
	for(loop=1;loop<n;loop++){//n��Ҷ�ӽ�㣬�����n-1��˫�ף�����ֻ��Ҫѭ��n-1�� 
		for(k1=0;k1<n&&!F[k1];k1++);//��k1��k2���ڲ���NULL�ĵط�
		for(k2=k1+1;k2<n&&!F[k2];k2++);
		for(i=k2;i<n;i++){//����С����Сֵ���±� 
			if(F[i]){//����NULL˵���Ѿ���Ϲ���  ��������Ҷ���Ѿ���ϳ�һ���µĸ������ 
			//�����뵽��ָ�������н�С���±괦 
				if(F[i]->weight<F[k1]->weight){
					k2=k1;
					k1=i;
				}
				else if(F[i]->weight<F[k2]->weight){
					k2=i;
				}
			}
		}
		//����˫��
		pa=(HuffNode *)malloc(sizeof(HuffNode)); 
		pa->word='O';//���˫�׽��  Ҳ���Բ�Ҫ
		pa->weight=F[k1]->weight+F[k2]->weight;//���ҵ�����С�ʹ�С�±��Ӧ�Ľ��Ȩֵ��ӹ����½���Ȩֵ
		pa->left=F[k1];//���� 
		pa->right=F[k2]; //����Ů��С ����Ů��С
		F[k1]=pa;//����F[k1]����˫�׽��
		F[k2]=NULL;//��֤�´β�����С����Сֵ�±����ȷ�ԣ������ظ�����   
	}
	return F[k1];//����ʣ��F[k1]��㣬����洢�ļ�ΪHuffman Tree�ĸ���� 
}

void PrintHuffmanTree(HuffNode *root)
{
	//ǰ�����
	if(root){
	 printf("%c:",root->word);
	 printf("%d\n",root->weight);
	 //printf("%5d",root->weight);
	 PrintHuffmanTree(root->left);
	 PrintHuffmanTree(root->right);
	}
}

int main()
{
	HuffNode *root;
	HuffNode **F;
	int i,n;
	//����ɭ��
	printf("������Ҷ�ӽ�������");
	scanf("%d",&n);
	fflush(stdin);
	F=(HuffNode **)malloc(n*sizeof(HuffNode *));
	printf("��ֱ�����Ҷ�ӽ������ƺ�Ȩ�أ�");
	for(i=0;i<n;i++){
		F[i]=(HuffNode *)malloc(sizeof(HuffNode));
		F[i]->left=F[i]->right=NULL;
		char c=F[i]->word;
		int t=F[i]->weight;
		scanf("%c%d",&F[i]->word,&F[i]->weight);
		fflush(stdin);
		//scanf("%d",&F[i]->weight);
	}
	root=CreateHuffmanTree(F,n);//������������
	PrintHuffmanTree(root);//����������� 
	return 0;
}*/

//����ʵ�ֹ���������
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char word;//���� 
	int weight;//Ȩ�� 
	int left,right,parent;
	int *code;//ִ���Ź���������������ָ�� 
}HuffNode;

void CreateHuffmanTree(HuffNode *F,int n)
{
	int loop;
	int k1,k2,i;
	for(loop=0;loop<n-1;loop++){//ѭ������n-1�Σ�����n-1��˫�׽�� 
		for(k1=0;k1<n+loop&&F[k1].parent!=-1;k1++);//k1��k2��λ��û��˫�׵�λ���� 
		for(k2=k1+1;k2<n+loop&&F[k2].parent!=-1;k2++);
		for(i=k2;i<n+loop;i++){//ѭ�������ҳ���С����Сֵ���±� 
			if(F[i].parent==-1){//˵���仹δ������Ҷ�Ӻϲ�������ֱ������ 
				if(F[i].weight<F[k1].weight){
					k2=k1;
					k1=i;
				}
				else if(F[i].weight<F[k2].weight){
					k2=i;
				}
			}
		}
		F[i].word='x';//������� 
		F[i].weight=F[k1].weight+F[k2].weight;//˫�׽���������Ҷ�ӽ����� 
		F[i].left=k1;//�߼��Ϲ�������ָ�� 
		F[i].right=k2;
		F[i].parent=-1;//�����ºϳɵĽ��parent����ֵ����-1 
		F[k1].parent=F[k2].parent=i;//�޸���Ů��parent�� 
	}
}

void CreateHuffmanCode(HuffNode *F,int n)
{
	int c,pa,i;
	int *p;
	for(i=0;i<n;i++){//������ǰn��Ҷ�ӽ�� 
		F[i].code=p=(int *)malloc(n*sizeof(int));//����n���ռ䣬p[0]�ռ���Ϊ����
		p[0]=0;
		c=i;
		while(F[c].parent!=-1){//������-1��˵���䲻Ϊ����㣬�����ѭ���������жϲ������ֵ����洢���������ռ� 
			pa=F[c].parent;
			if(F[pa].left==c){//pa��ָ�������left�����c��˵����Ϊ��������Ů�����Ա���Ϊ0 
				p[++p[0]]=0;
			}
			else{//˵����Ϊ��������Ů�����Ա���Ϊ1 
				p[++p[0]]=1;
			} 
			c=pa; //c����ָ����˫�׽�� 
		} 
	}
}

void PrintHuffmanCode(HuffNode *F,int n)
{
	for(int i=0;i<n;i++){//ѭ����������n��Ҷ�ӽ�� 
		//������Ӧ�Ĺ���������
		printf("%c:",F[i].word);//�����Ӧ�ַ� 
		for(int j=F[i].code[0];j>0;j--){//ѭ�������Ӧ�ַ��Ĺ���������,���������������ڵ�1��ֵ
		//��Ӧ��ӦҶ�ӽ��ĸ���Ҷ�ӽ��Ĺ��������� 
			printf("%d",F[i].code[j]); 
		} 
		printf("\n");
	}
}

int main()
{
	HuffNode *F;
	int n,i;
	char ch;
	int w;
	printf("������Ҷ�ӽ�������");
	scanf("%d",&n);
	fflush(stdin);
	printf("������Ҷ�ӽ������ƺ�Ȩֵ��");
	//����ɭ��
	F=(HuffNode *)malloc((2*n-1)*sizeof(HuffNode));//n��Ҷ�ӽ�㣬���ɵĹ��������У������2n-1����� 
	for(i=0;i<n;i++){
	 		scanf("%c",&F[i].word);
	 		scanf("%d",&F[i].weight);
	 		fflush(stdin);
	 		F[i].left=F[i].weight=F[i].parent=-1;
	 	}
	//������������
	CreateHuffmanTree(F,n);
	//����HuffmanCode
	CreateHuffmanCode(F,n);
	//���
	PrintHuffmanCode(F,n);
	return 0; 
}


