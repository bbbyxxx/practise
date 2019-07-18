#include<stdio.h>
#define N  6
typedef struct {
	int c,r;
}Stack;
Stack s[N*N];
Stack result[N*N];	
int Min=N*N; 
int top=-1;
int m1[N+2][N+2]={
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
{0 ,1 ,1 ,0 ,0 ,0 ,0 ,0},
{0 ,1 ,1 ,1 ,1 ,0 ,0, 0},
{0, 0 ,0 ,0 ,1 ,0 ,0 ,0},
{0, 0, 0, 0, 1, 1, 0, 0},
{0 ,0, 0, 0 ,0, 1, 0, 0},
{0 ,0 ,0 ,0 ,0 ,1 ,1 ,0},
{0 ,0, 0, 0, 0, 0, 0, 0}
};  
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};	//南东北西 


void Count()
{
	if(top<Min){
		Min=top;
		int i;
		for(i=0;i<=top;i++){
			result[i].c=s[i].c;
			result[i].r=s[i].r;
		}	
	}
} 
void Print()
{
	int i;
	for(i=0;i<=top;i++){
		printf("(%d,%d)-->",s[i].c,s[i].r); 
	}
	printf("\n\n");
}
void Maze(int x,int y)
{
	if(x==6&&y==6){
		Print();
		Count();
		return ;
	}
	for(int i=0;i<4;i++){
		int a=x+move[i][0];
		int b=y+move[i][1];
		if(m1[a][b]==1){
			++top;
			s[top].c=a;
			s[top].r=b;
			m1[a][b]=2;
			Maze(a,b);
			m1[a][b]=1;
			--top;
		}
	}
}

int main(void)
{
	++top;
	s[top].c =s[top].r=1; 
	Maze(1,1);
	//输出最优解
	printf("其中一条最短路径为：\n");
	int i;
	for(i=0;i<=Min;i++)
		printf("(%d,%d)-->",result[i].c,result[i].r); 
	return 0; 
}


/*
#include<stdio.h>
#define N  6
typedef struct {
	int c,r;
}Stack;
Stack s[N*N];
Stack result[N*N];	//最优解
int Min=N*N; 
int top=-1;
int m1[N+2][N+2]={
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
{0 ,1 ,0 ,0 ,0 ,0 ,0 ,0},
{0 ,1 ,1 ,1 ,0 ,0 ,0, 0},
{0, 1 ,1 ,1 ,1 ,0 ,0 ,0},
{0, 1, 1, 0, 1, 1, 0, 0},
{0 ,1, 1, 1 ,1, 1, 1, 0},
{0 ,1 ,0 ,0 ,0 ,1 ,1 ,0},
{0 ,0, 0, 0, 0, 0, 0, 0}
};
int m2[N+2][N+2]={0};	//存储走过的路径，防止反复走  
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};	//南东北西 


void Count()
{
	if(top<Min){
		Min=top;
		int i;
		for(i=0;i<=top;i++){
			result[i].c=s[i].c;
			result[i].r=s[i].r;
		}	
	}
} 
void Print()
{
	int i;
	for(i=0;i<=top;i++){
		printf("(%d,%d)-->",s[i].c,s[i].r); 
	}
	printf("\n\n");
}
void Maze(int x,int y)
{
	if(x==6&&y==6){
		Print();
		Count();
		return ;
	}
	for(int i=0;i<4;i++){
		int a=x+move[i][0];
		int b=y+move[i][1];
		if(m1[a][b]&&!m2[a][b]){
			++top;
			s[top].c=a;
			s[top].r=b;
			m2[a][b]=1;
			Maze(a,b);
			m2[a][b]=0;
			--top;
		}
	}
}

int main(void)
{
	++top;
	s[top].c =s[top].r=1; 
	Maze(1,1);
	//输出最优解
	printf("\n最短路径：\n");
	int i;
	for(i=0;i<=Min;i++)
		printf("(%d,%d)-->",result[i].c,result[i].r); 
	return 0; 
}

*/
