#include<stdio.h>
#include<stdlib.h>
#define R 7//�� 
#define C 8//�� 
int M[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,1,1,1},
		{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
int T[R+2][C+2]={0};//�����̽����·��
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//�ֱ��ʾ���ϡ�����������
int tag=0;
int stack[100][2]={0};//����һ��ջ�ռ��ȡ·�� 
int top=0;//��Ϊstack[0][0]λ���Ѿ����˳�ֵ 
int Min=2147483647;
int result[100][2]={0};

void Count()
{
	if(top<Min){
		Min=top;
		int i;
		for(i=0;i<=top;i++){
			result[i][0]=stack[i][0];
			result[i][1]=stack[i][1];
		}	
	}
} 

void Print()
{
	printf("�Թ�Ϊ��\n");
	for(int i=1;i<R+1;i++){
		for(int j=1;j<C+1;j++){
			printf("%d  ",M[i][j]);
		}
		printf("\n");
	} 
}

void PrintStack()
{
	for(int i=0;i<top+1;i++){//����ջ ��� 
		printf("(%d,%d) ",stack[i][0],stack[i][1]);
	} 
	printf("\n");
}

void Maze(int x,int y)
{
	if(x==R&&y==C){
		tag=1;
		Count();
		PrintStack();
	} 
	else{
		for(int i=0;i<4;i++){//�����ĸ����� 
			int a=x+Move[i][0];//a,bΪ��Ҫ��̽��λ������ 
			int b=y+Move[i][1];
			if(!M[a][b]&&!T[a][b]){//��·����û�߹� Y��ִ�����淽����  N����������������̽�� 
				T[a][b]=1;//������߹���· 
				top++;
				stack[top][0]=a;//��ջ
				stack[top][1]=b; 
				Maze(a,b);//����̽�� 
				T[a][b]=0;
				top--;
			}
		} 
	}
}

int main()
{
	Print(); 
	stack[top][0]=stack[top][1]=1;
	Maze(1,1);//���߳��Թ���·�� 
	if(!tag){
		printf("û�г��ڣ�");
	}
	printf("������·��Ϊ:");
	for(int i=0;i<=Min;i++){
			printf("(%d,%d)",result[i][0],result[i][1]);
		}
	return 0;
} 
