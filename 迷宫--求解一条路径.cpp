#include<stdio.h>
#include<stdlib.h>
#define R 7//行 
#define C 8//列 
int M[R+2][C+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,1,1,1,1},{1,0,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,1},{1,0,0,1,1,0,0,0,0,1},{1,0,0,0,1,1,1,0,0,1},
		{1,1,0,0,0,1,1,0,0,1},{1,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1}};
int T[R+2][C+2]={0};//标记试探过的路径
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//分别表示向南、东、北、西
int tag;

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

int Maze(int x,int y)
{
	if(x==R&&y==C){
		return 1;
	} 
	for(int i=0;i<4;i++){//遍历四个方向 
		int a=x+Move[i][0];//a,b为将要试探的位置坐标 
		int b=y+Move[i][1];
		if(M[a][b]!=1&&!T[a][b]){//是路并且没走过 Y：执行下面方法体  N：继续向其他方向探察 
			T[a][b]=1;//标记已走过的路 
			tag=Maze(a,b);//继续探察 
			if(tag==1){//tag==1说明有一条路径，即已经走到出口了 
				printf("(%d,%d)  ",a,b);
				return tag;
			} 
		}
	}
	return 0;
}

int main()
{
	for(int i=0;i<R+2;i++){
		for(int j=0;j<C+2;j++){
			if(i==0||i==R+1||j==0||j==C+1){
				M[i][j]=1;
			}
		}
	}
	//InitM();//建立迷宫 
	Print(); 
	tag=Maze(1,1);//求走出迷宫路径 
	if(tag==1){
	printf("(1,1)");//入口点需要单独输出，因为调用上面函数返回的是	
	}
	else{
		printf("没有出口！");
	}
	return 0;
} 
