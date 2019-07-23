#include<stdio.h>
#include<stdlib.h>
#define R 7//行 
#define C 8//列 
int M[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,1,1,1},
		{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,1,0,1,1,1},{1,1,1,1,1,1,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
int T[R+2][C+2]={0};//标记试探过的路径
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//分别表示向南、东、北、西
int tag=0;
int stack[100][2]={0};//声明一个栈空间存取路径 
int top=0;//因为stack[0][0]位置已经赋了初值 
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
	printf("迷宫为：\n");
	for(int i=1;i<R+1;i++){
		for(int j=1;j<C+1;j++){
			printf("%d  ",M[i][j]);
		}
		printf("\n");
	} 
}

void PrintStack()
{
	for(int i=0;i<top+1;i++){//遍历栈 输出 
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
		for(int i=0;i<4;i++){//遍历四个方向 
			int a=x+Move[i][0];//a,b为将要试探的位置坐标 
			int b=y+Move[i][1];
			if(!M[a][b]&&!T[a][b]){//是路并且没走过 Y：执行下面方法体  N：继续向其他方向探察 
				T[a][b]=1;//标记已走过的路 
				top++;
				stack[top][0]=a;//入栈
				stack[top][1]=b; 
				Maze(a,b);//继续探察 
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
	Maze(1,1);//求走出迷宫的路径 
	if(!tag){
		printf("没有出口！");
	}
	printf("输出最短路径为:");
	for(int i=0;i<=Min;i++){
			printf("(%d,%d)",result[i][0],result[i][1]);
		}
	return 0;
} 
