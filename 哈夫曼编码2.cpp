//链表创建Huffman Tree 

/*#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char word;//名称 
	int weight;//权重 
	struct node *left,*right;
}HuffNode;

HuffNode *CreateHuffmanTree(HuffNode **F,int n)
{
	int loop,i,k1,k2;
	HuffNode *pa;
	for(loop=1;loop<n;loop++){//n个叶子结点，最多有n-1个双亲，所以只需要循环n-1次 
		for(k1=0;k1<n&&!F[k1];k1++);//将k1和k2放在不是NULL的地方
		for(k2=k1+1;k2<n&&!F[k2];k2++);
		for(i=k2;i<n;i++){//找最小、次小值的下标 
			if(F[i]){//遇到NULL说明已经结合过了  就是两个叶子已经结合成一个新的根结点了 
			//并塞入到了指针数组中较小的下标处 
				if(F[i]->weight<F[k1]->weight){
					k2=k1;
					k1=i;
				}
				else if(F[i]->weight<F[k2]->weight){
					k2=i;
				}
			}
		}
		//创建双亲
		pa=(HuffNode *)malloc(sizeof(HuffNode)); 
		pa->word='O';//标记双亲结点  也可以不要
		pa->weight=F[k1]->weight+F[k2]->weight;//将找到的最小和次小下标对应的结点权值相加构成新结点的权值
		pa->left=F[k1];//挂链 
		pa->right=F[k2]; //左子女最小 右子女次小
		F[k1]=pa;//假设F[k1]存在双亲结点
		F[k2]=NULL;//保证下次查找最小，次小值下标的正确性，避免重复计算   
	}
	return F[k1];//最后仅剩下F[k1]结点，里面存储的即为Huffman Tree的根结点 
}

void PrintHuffmanTree(HuffNode *root)
{
	//前序遍历
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
	//创建森林
	printf("请输入叶子结点个数：");
	scanf("%d",&n);
	fflush(stdin);
	F=(HuffNode **)malloc(n*sizeof(HuffNode *));
	printf("请分别输入叶子结点的名称和权重：");
	for(i=0;i<n;i++){
		F[i]=(HuffNode *)malloc(sizeof(HuffNode));
		F[i]->left=F[i]->right=NULL;
		char c=F[i]->word;
		int t=F[i]->weight;
		scanf("%c%d",&F[i]->word,&F[i]->weight);
		fflush(stdin);
		//scanf("%d",&F[i]->weight);
	}
	root=CreateHuffmanTree(F,n);//创建哈夫曼树
	PrintHuffmanTree(root);//输出哈夫曼树 
	return 0;
}*/

//数组实现哈夫曼编码
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char word;//名称 
	int weight;//权重 
	int left,right,parent;
	int *code;//执向存放哈夫曼编码的数组的指针 
}HuffNode;

void CreateHuffmanTree(HuffNode *F,int n)
{
	int loop;
	int k1,k2,i;
	for(loop=0;loop<n-1;loop++){//循环遍历n-1次，生成n-1个双亲结点 
		for(k1=0;k1<n+loop&&F[k1].parent!=-1;k1++);//k1，k2定位到没有双亲的位置上 
		for(k2=k1+1;k2<n+loop&&F[k2].parent!=-1;k2++);
		for(i=k2;i<n+loop;i++){//循环遍历找出最小、次小值的下标 
			if(F[i].parent==-1){//说明其还未与其他叶子合并，否则直接跳过 
				if(F[i].weight<F[k1].weight){
					k2=k1;
					k1=i;
				}
				else if(F[i].weight<F[k2].weight){
					k2=i;
				}
			}
		}
		F[i].word='x';//标记名称 
		F[i].weight=F[k1].weight+F[k2].weight;//双亲结点等于两个叶子结点相加 
		F[i].left=k1;//逻辑上挂链，即指向 
		F[i].right=k2;
		F[i].parent=-1;//对于新合成的结点parent赋初值，即-1 
		F[k1].parent=F[k2].parent=i;//修改子女的parent域 
	}
}

void CreateHuffmanCode(HuffNode *F,int n)
{
	int c,pa,i;
	int *p;
	for(i=0;i<n;i++){//遍历当前n个叶子结点 
		F[i].code=p=(int *)malloc(n*sizeof(int));//分配n个空间，p[0]空间作为岗哨
		p[0]=0;
		c=i;
		while(F[c].parent!=-1){//不等于-1，说明其不为根结点，则进入循环，持续判断并求编码值赋予存储编码的数组空间 
			pa=F[c].parent;
			if(F[pa].left==c){//pa所指的数组的left域等于c，说明其为它的左子女，所以编码为0 
				p[++p[0]]=0;
			}
			else{//说明其为它的右子女，所以编码为1 
				p[++p[0]]=1;
			} 
			c=pa; //c重新指向其双亲结点 
		} 
	}
}

void PrintHuffmanCode(HuffNode *F,int n)
{
	for(int i=0;i<n;i++){//循环遍历它的n个叶子结点 
		//输出其对应的哈夫曼编码
		printf("%c:",F[i].word);//输出对应字符 
		for(int j=F[i].code[0];j>0;j--){//循环输出对应字符的哈夫曼编码,即倒着输出数组岗哨到1的值
		//对应相应叶子结点的根到叶子结点的哈夫曼编码 
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
	printf("请输入叶子结点个数：");
	scanf("%d",&n);
	fflush(stdin);
	printf("请输入叶子结点的名称和权值：");
	//创建森林
	F=(HuffNode *)malloc((2*n-1)*sizeof(HuffNode));//n个叶子结点，生成的哈夫曼树中，最多有2n-1个结点 
	for(i=0;i<n;i++){
	 		scanf("%c",&F[i].word);
	 		scanf("%d",&F[i].weight);
	 		fflush(stdin);
	 		F[i].left=F[i].weight=F[i].parent=-1;
	 	}
	//创建哈夫曼树
	CreateHuffmanTree(F,n);
	//创建HuffmanCode
	CreateHuffmanCode(F,n);
	//输出
	PrintHuffmanCode(F,n);
	return 0; 
}


