//稀疏矩阵：零元素多于非零元素的矩阵
/*
稀疏矩阵零元素多于非零元素，而这些零元素是没有意义的
这样会造成空间的浪费，因此，采用下面的方法来存储非零元素
已达到节省空间的效果 
*/

#include<bits/stdc++.h>
#define Maxterms 10
#define MaxRows  6
#define MaxColumns 6

//为了统一，下标为0的空间浪费掉 

//顺序存储--三元组
struct Triple{
	int row,col;//存储行号和列号 
	int val;//存储非零元素值 
}; 
struct SMatrix{
	int m,n,t;//m存储行数，n存储列数，t存储非零元素个数
	struct Triple sm[Maxterms+1]; 
};
 
//链式存储--带行指针向量的链式存储 
/*
将具有相同行号的三元组结点按照列号从小到大的顺序链接成一个单链表
每个单链表都需要一个头指针，因此还需要一个行指针向量（即一维数组）
该分量的第i个分量，即对应稀疏矩阵中的第i行 
*/
struct TripleNode{
	int row,col;//存储行号和列号
	int val;//存储非零元素值
	struct TripleNode *next;//指向同一行的下一个结点 
};
struct LMatrix{
	int m,n,t;//同上 
	struct TripleNode *lm[Maxterms+1];
}; 

//链式存储--十字链表存储
/*
十字链表存储就是既带行指针向量又带列指针向量的链式存储。
在这种存储方式下，每个三元组结点既处于同一行的单链表中，也处于同一列的单链表中
即处于所在行单链表和列单链表的交点处 
*/ 
struct CrossNode{
	int row,col;
	int val;
	struct CrossNode *down,*right;//down指向同一列下一个结点，right指向同一行下一个结点 
}; 
struct CLMatrix{
	int m,n,t;
	struct CrossNode *rm[MaxRows+1];
	struct CrossNode *cm[MaxColumns+1];
};

//初始化运算

//对于SMatrix类型的对象，初始化过程如下
void InitMatrix1(struct SMatrix *M)
{
	M->m=0;
	M->n=0;
	M->t=0;
} 

//对于LMatrix类型的对象，初始化过程如下
void InitMatrix2(struct LMatrix *M)
{
	int i;
	M->m=0;
	M->n=0;
	M->t=0;
	for(i=1;i<=MaxRows;i++){
		M->lm[i]=NULL;
	}
} 

//对于CLMatrix类型的对象，初始化过程如下
void InitMatrix3(struct CLMatrix *M)
{
	int i;
	M->m=0;
	M->n=0;
	M->t=0;
	for(i=1;i<=MaxRows;i++){
		M->rm[i]=NULL;
	}
	for(i=0;i<=MaxRows;i++){
		M->cm[i]=NULL;
	}
	
} 

//稀疏矩阵的建立
/*
采用键盘输入，输入对应三元组线性表中三元组排列的次序，每行输入一个三元组 
以（0,0,0）作为输入结束标志 
*/

//采用三元组存储 
void InputMatrix1(struct SMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	int val;
	M->m=m;
	M->n=n; 
	printf("请输入每个三元组：");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		k++;
		M->sm[k].row=row;
		M->sm[k].col=col;
		M->sm[k].val=val;
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

//采用十字链表存储 
void InputMatrix3(struct CLMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	int val;
	M->m=m;
	M->n=n;
	printf("请输入每个三元组：");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		struct CrossNode *cp,*newp;
		k++;
		//建立新结点并赋值
		newp=(struct CrossNode *)malloc(sizeof(struct CrossNode));
		newp->row=row;
		newp->col=col;
		newp->val=val;
		newp->right=newp->down=NULL;
		//将新结点链接在所在行单链表的末尾
		cp=M->rm[row];
		if(cp==NULL){
			M->rm[row]=newp;//直接挂链 
		}
		else{
			while(cp->right!=NULL){
				cp=cp->right;//cp后移 
			}
			cp->right=newp;//找到位置，挂链 
		}
		//将新结点链接在所在列单链表的末尾
		cp=M->cm[col];
		if(cp==NULL){
			M->cm[col]=newp;
		} 
		else{
			while(cp->down!=NULL){
				cp=cp->down;
			}
			cp->down=newp;
		}
		//输入下一个三元组 
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

//稀疏矩阵的输出

//按三元组线性表的格式输出
void OutputMatrix1(struct SMatrix *M)
{
	int i;
	//输出线性表开始的左括号
	printf("(");
	//输出前M->t-1个三元组元素
	 for(i=1;i<M->t;i++){
	 	printf("(%d %d %d),",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	 } 
	 //输出最后一组
	 if(M->t!=0){
	 	printf("(%d %d %d)",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	 } 
	 //输出线性表最后的右括号
	 printf(")\n"); 
}

//采用带行指针向量的链式存储的稀疏矩阵的输出
void OutputMatrix2(struct LMatrix *M)
{
	int i;
	struct TripleNode *p;
	printf("(");
	for(i=1;i<=M->m;i++){
		for(p=M->lm[i];p!=NULL;p=p->next){
			printf("(%d %d %d),",p->row,p->col,p->val);
		}
	}
	printf(")\n");
} 

//稀疏矩阵的转置运算
struct SMatrix *TransposeMatrix(struct SMatrix *M)
{
	int m,n,t;
	int k,i,col;
	//用S暂存转置结果，以便返回
	struct SMatrix *S;
	S=(struct SMatrix *) malloc(sizeof(struct SMatrix));
	InitMatrix1(S);//初始化 
	//用m，n，t暂存M的行数，列数，和非零元素个数
	m=M->m;
	n=M->n;
	t=M->t;
	//分别置S的行数，列数，非零元素个数为n，m，t
	S->m=n;
	S->n=m;
	S->t=t;
	//若是零矩阵（即非零元素个数为零），则转换完毕返回
	if(t==0){
		return S;
	} 
	//用k指示S->sm数组中待存元素的下标，初值为1
	k=1;
	//按列进行每个元素的转换，用col扫描M->sm数组中的列号col域
	for(col=1;col<=n;col++){
		//用i指示M->sm数组中待扫描元素的下标
		for(i=1;i<=t;i++){
			if(M->sm[i].col==col){
				S->sm[k].row=col;
				S->sm[k].col=M->sm[i].row;
				S->sm[k].val=M->sm[i].val;
				k++;
			}
		} 
	}
	return S; 
}

//快速转置算法
struct SMatrix * FastTransposeMatrix(struct SMatrix *M,struct SMatrix *N)
{
	int j,q,p,t;
	int number[M->n+1];
	int position[M->n+1];
	N->m=M->n;
	N->n=M->m;
	N->t=M->t;
	if(M->t){
		for(j=1;j<=M->n;j++){//矩阵M每一列非零元素初始化为零 
			number[j]=0;
			position[j]=0; 
		} 
		for(t=1;t<=M->t;t++){
			number[M->sm[t].col]++;//求矩阵M每一列的非零元素个数 
		}
		position[1]=1;
		for(j=2;j<=M->n;j++){//求M.sm第j列第一个非零元素在N.sm的序号 
			position[j]=position[j-1]+number[j-1];
		}
		for(p=1;p<=M->t;p++){//求转置矩阵N的三元组表 
			j=M->sm[p].col;
			q=position[j];
			N->sm[q].row=M->sm[p].col;
			N->sm[q].col=M->sm[p].row;
			N->sm[q].val=M->sm[p].val;
		} 
	}
	return N; 
} 


int main()
{
	int m,n;
	printf("请输入行数和列数：");
	scanf("%d %d",&m,&n);
	struct SMatrix M,N;
	InitMatrix1(&M);//初始化 
	InputMatrix1(&M,m,n);//建立 
	OutputMatrix1(&M);//输出 
	InitMatrix1(&N);//初始化N
	/*struct SMatrix *Transpose=TransposeMatrix(&M);//一般转置算法 
	OutputMatrix1(Transpose);//输出转置矩阵*/
	struct SMatrix *FastTranspose=FastTransposeMatrix(&M,&N);//快速转置算法
	OutputMatrix1(FastTranspose);//输出转置矩阵 
	return 0;
}
