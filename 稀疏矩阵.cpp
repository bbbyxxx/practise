//ϡ�������Ԫ�ض��ڷ���Ԫ�صľ���
/*
ϡ�������Ԫ�ض��ڷ���Ԫ�أ�����Щ��Ԫ����û�������
��������ɿռ���˷ѣ���ˣ���������ķ������洢����Ԫ��
�Ѵﵽ��ʡ�ռ��Ч�� 
*/

#include<bits/stdc++.h>
#define Maxterms 10
#define MaxRows  6
#define MaxColumns 6

//Ϊ��ͳһ���±�Ϊ0�Ŀռ��˷ѵ� 

//˳��洢--��Ԫ��
struct Triple{
	int row,col;//�洢�кź��к� 
	int val;//�洢����Ԫ��ֵ 
}; 
struct SMatrix{
	int m,n,t;//m�洢������n�洢������t�洢����Ԫ�ظ���
	struct Triple sm[Maxterms+1]; 
};
 
//��ʽ�洢--����ָ����������ʽ�洢 
/*
��������ͬ�кŵ���Ԫ���㰴���кŴ�С�����˳�����ӳ�һ��������
ÿ����������Ҫһ��ͷָ�룬��˻���Ҫһ����ָ����������һά���飩
�÷����ĵ�i������������Ӧϡ������еĵ�i�� 
*/
struct TripleNode{
	int row,col;//�洢�кź��к�
	int val;//�洢����Ԫ��ֵ
	struct TripleNode *next;//ָ��ͬһ�е���һ����� 
};
struct LMatrix{
	int m,n,t;//ͬ�� 
	struct TripleNode *lm[Maxterms+1];
}; 

//��ʽ�洢--ʮ������洢
/*
ʮ������洢���Ǽȴ���ָ�������ִ���ָ����������ʽ�洢��
�����ִ洢��ʽ�£�ÿ����Ԫ����ȴ���ͬһ�еĵ������У�Ҳ����ͬһ�еĵ�������
�����������е�������е�����Ľ��㴦 
*/ 
struct CrossNode{
	int row,col;
	int val;
	struct CrossNode *down,*right;//downָ��ͬһ����һ����㣬rightָ��ͬһ����һ����� 
}; 
struct CLMatrix{
	int m,n,t;
	struct CrossNode *rm[MaxRows+1];
	struct CrossNode *cm[MaxColumns+1];
};

//��ʼ������

//����SMatrix���͵Ķ��󣬳�ʼ����������
void InitMatrix1(struct SMatrix *M)
{
	M->m=0;
	M->n=0;
	M->t=0;
} 

//����LMatrix���͵Ķ��󣬳�ʼ����������
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

//����CLMatrix���͵Ķ��󣬳�ʼ����������
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

//ϡ�����Ľ���
/*
���ü������룬�����Ӧ��Ԫ�����Ա�����Ԫ�����еĴ���ÿ������һ����Ԫ�� 
�ԣ�0,0,0����Ϊ���������־ 
*/

//������Ԫ��洢 
void InputMatrix1(struct SMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	int val;
	M->m=m;
	M->n=n; 
	printf("������ÿ����Ԫ�飺");
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

//����ʮ������洢 
void InputMatrix3(struct CLMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	int val;
	M->m=m;
	M->n=n;
	printf("������ÿ����Ԫ�飺");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		struct CrossNode *cp,*newp;
		k++;
		//�����½�㲢��ֵ
		newp=(struct CrossNode *)malloc(sizeof(struct CrossNode));
		newp->row=row;
		newp->col=col;
		newp->val=val;
		newp->right=newp->down=NULL;
		//���½�������������е������ĩβ
		cp=M->rm[row];
		if(cp==NULL){
			M->rm[row]=newp;//ֱ�ӹ��� 
		}
		else{
			while(cp->right!=NULL){
				cp=cp->right;//cp���� 
			}
			cp->right=newp;//�ҵ�λ�ã����� 
		}
		//���½�������������е������ĩβ
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
		//������һ����Ԫ�� 
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

//ϡ���������

//����Ԫ�����Ա�ĸ�ʽ���
void OutputMatrix1(struct SMatrix *M)
{
	int i;
	//������Ա�ʼ��������
	printf("(");
	//���ǰM->t-1����Ԫ��Ԫ��
	 for(i=1;i<M->t;i++){
	 	printf("(%d %d %d),",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	 } 
	 //������һ��
	 if(M->t!=0){
	 	printf("(%d %d %d)",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	 } 
	 //������Ա�����������
	 printf(")\n"); 
}

//���ô���ָ����������ʽ�洢��ϡ���������
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

//ϡ������ת������
struct SMatrix *TransposeMatrix(struct SMatrix *M)
{
	int m,n,t;
	int k,i,col;
	//��S�ݴ�ת�ý�����Ա㷵��
	struct SMatrix *S;
	S=(struct SMatrix *) malloc(sizeof(struct SMatrix));
	InitMatrix1(S);//��ʼ�� 
	//��m��n��t�ݴ�M���������������ͷ���Ԫ�ظ���
	m=M->m;
	n=M->n;
	t=M->t;
	//�ֱ���S������������������Ԫ�ظ���Ϊn��m��t
	S->m=n;
	S->n=m;
	S->t=t;
	//��������󣨼�����Ԫ�ظ���Ϊ�㣩����ת����Ϸ���
	if(t==0){
		return S;
	} 
	//��kָʾS->sm�����д���Ԫ�ص��±꣬��ֵΪ1
	k=1;
	//���н���ÿ��Ԫ�ص�ת������colɨ��M->sm�����е��к�col��
	for(col=1;col<=n;col++){
		//��iָʾM->sm�����д�ɨ��Ԫ�ص��±�
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

//����ת���㷨
struct SMatrix * FastTransposeMatrix(struct SMatrix *M,struct SMatrix *N)
{
	int j,q,p,t;
	int number[M->n+1];
	int position[M->n+1];
	N->m=M->n;
	N->n=M->m;
	N->t=M->t;
	if(M->t){
		for(j=1;j<=M->n;j++){//����Mÿһ�з���Ԫ�س�ʼ��Ϊ�� 
			number[j]=0;
			position[j]=0; 
		} 
		for(t=1;t<=M->t;t++){
			number[M->sm[t].col]++;//�����Mÿһ�еķ���Ԫ�ظ��� 
		}
		position[1]=1;
		for(j=2;j<=M->n;j++){//��M.sm��j�е�һ������Ԫ����N.sm����� 
			position[j]=position[j-1]+number[j-1];
		}
		for(p=1;p<=M->t;p++){//��ת�þ���N����Ԫ��� 
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
	printf("������������������");
	scanf("%d %d",&m,&n);
	struct SMatrix M,N;
	InitMatrix1(&M);//��ʼ�� 
	InputMatrix1(&M,m,n);//���� 
	OutputMatrix1(&M);//��� 
	InitMatrix1(&N);//��ʼ��N
	/*struct SMatrix *Transpose=TransposeMatrix(&M);//һ��ת���㷨 
	OutputMatrix1(Transpose);//���ת�þ���*/
	struct SMatrix *FastTranspose=FastTransposeMatrix(&M,&N);//����ת���㷨
	OutputMatrix1(FastTranspose);//���ת�þ��� 
	return 0;
}
