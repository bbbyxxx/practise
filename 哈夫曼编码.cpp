#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct{
	char data[5];//名称 
	float weight;//权重
	int parent;//双亲结点
	int lchild;//左孩子结点 
	int rchild;//右孩子结点 
}HTNode;



typedef struct{
	char cd[N];//存放当前结点的哈夫曼编码 
	int start;//start指向cd数组中最开始的数的下标 
}HCode;

void CreateHuffmanTree(HTNode ht[],int n)
{
	int i,j,k,lnode,rnode;
	float min1,min2;
	for(i=0;i<2*n-1;i++){//所有结点的双亲，左右孩子域赋值-1 
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	} 
	for(i=n;i<2*n-1;i++){//因为0~n-1存的是叶子结点的权值，所以从n开始到2n-2，n个叶子结点的Huffman树，总共有2n-1个结点 
		min1=min2=32767;//尽可能大，这样比较得的小值则会赋给min
		lnode=rnode=-1;//最小权重的两个结点下标 
		for(k=0;k<i;k++){//在原数组范围内寻找，依次将新值插入然后将新值有作为原值，来查找权值最小的两个结点 
			if(ht[k].parent==-1){//只在尚未构建二叉树的结点中查找 
				if(ht[k].weight<=min1){//小于最小 
					min2=min1;//次小跟随最小 
					rnode=lnode;//指向次小权值结点的指针更新 
					min1=ht[k].weight;//最小值更新 
					lnode=k;//最小值的指针更新 
				}
				else if(ht[k].weight<min2){//不下于最小，小于次小 
					min2=ht[k].weight;//更新次小值 
					rnode=k;//更新指向次小值的指针 
				}
			}
		}//for（k）   得到次小，最小 
			ht[lnode].parent=i;
			ht[rnode].parent=i;
			ht[i].weight=ht[lnode].weight+ht[rnode].weight;//得到新的权值 
			ht[i].lchild=lnode;//指向最小权值结点 
			ht[i].rchild=rnode;//指向次小权值结点 
	}
}

void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,f,c;
	HCode hc;
	for(i=0;i<n;i++){//根据Huffman树求哈夫曼编码 
		hc.start=n;
		c=i;//每次指向当前叶子结点的下标 
		f=ht[i].parent;//f每次指向当前叶子结点的双亲 
		while(f!=-1){//循环直到无双亲结点的结点，即根结点 
			if(ht[f].lchild==c){//是左孩子 
				hc.cd[hc.start--]='0';
			}
			else{//是右孩子 
				hc.cd[hc.start--]='1';
			}
			c=f;//c更新为双亲结点 
			f=ht[f].parent;//f更新为双亲结点的双亲 
		}
		hc.start++;//求得哈夫曼编码的start是指向其前一个元素，应该加一指向最开始元素 
		hcd[i]=hc;//hcd数组接收当前叶子结点哈夫曼编码和start值 
	}
}

void Print(HTNode ht[],int n)
{
	for(int i=n;i<2*n-1;i++){
		//printf("%c+%c=%5.2f\n",ht[ht[i].lchild].data,ht[ht[i].rchild].data,ht[i].weight);
		printf("%5.2f\n",ht[i].weight);
	}
}

void PrintHuffmanCode(HTNode ht[],HCode hcd[],int n)
{
	int i,k,j;
	double sum=0,m=0;
	printf("输出的哈夫曼编码为：\n");
	for(i=0;i<n;i++){
		j=0;//计算带权路径长度 
		printf("%s::",ht[i].data);
		for(k=hcd[i].start;k<=n;k++){
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		m+=ht[i].weight;//计算叶子结点权重之和 
		sum+=ht[i].weight*j;//计算带权路径长度值
		printf("\n");
	} 
	printf("m=%5.2lf，n=%5.2lf",m,sum);//输出带权路径长度值 
}

int main()
{
	int n;
	printf("请输入叶子结点个数:");
	scanf("%d",&n);
	HTNode ht[n*2-1];
	printf("请输入叶子结点的权值：");
	int i=0;
	while(i<n){
		scanf("%s %f",ht[i].data,&ht[i].weight);
		i++;
	}
	CreateHuffmanTree(ht,n);//创建哈夫曼树 
	Print(ht,n);//输出合成的根结点的权重 
	HCode hcd[n];//存取n个叶子结点的哈夫曼编码 
	CreateHCode(ht,hcd,n);//求取对应的哈夫曼编码 
	PrintHuffmanCode(ht,hcd,n);//输出各叶子结点的哈夫曼编码 
	return 0;
}
