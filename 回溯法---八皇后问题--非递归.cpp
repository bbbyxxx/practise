//回溯法（试探法）---八皇后问题--非递归 
//打印一组解 
/*#include<stdio.h>
int col[8]={0};
int left[15]={0};
int right[15]={0};
int Q[8]={0};
void Queen(void)
{
	int top,i,j;
	i=0;
	top=-1;
	j=0;
	while(top!=7){//栈不满
		for(;j<8;j++){//遍历i行的8列 
			if(!col[j]&&!left[i+j]&&!right[7+i-j]){//放皇后 
				Q[++top]=j;//将放入皇后的列号入栈 
				col[j]=left[i+j]=right[7+i-j]=1;//说明已经放了皇后，标记列、斜线
				i++;//进入下一行 
				j=0;//对于下一行，j要从0开始遍历整行 
				break;//放好了皇后就跳出 
			}
		} 
		if(j==8){//如果j==8，说明一行跑完了 
			i--;//因为i行不能放，所以i要减一，回到其上一行，这样就可以进行下面步骤，抹掉当前行的皇后了
			j=Q[top--];//抹掉第i行的皇后
			col[j]=left[i+j]=right[7+i-j]=0;//重置0，表示此列、斜线无皇后
			j++;//跳过当前行 皇后，也就是抹掉了它，进而进行当前行下一个位置的判断 
		}
	}
}


int main()
{
	int i;
	Queen();
	for(i=0;i<8;i++){
		for(int j=0;j<8;j++){
		if(Q[i]==j){//皇后的位置 其中下标i为行数，Q[i]的值为对应的列数 
		printf("X  ");//标记皇后 
		}
		else{
			printf("0  ");
		} 
		}
		printf("\n");
	}
	return 0;
}*/


//N皇后问题--打印第一组解 
/*#include<stdio.h>
#define N 4//N皇后 
int col[N]={0};
int left[2*N-1]={0};
int right[2*N-1]={0};
int Q[N]={0};
void Queen(void)
{
	int top,i,j;
	i=0;
	top=-1;
	j=0;
	while(top!=N-1){//栈不满
		for(;j<N;j++){//遍历i行的8列 
			if(!col[j]&&!left[i+j]&&!right[N-1+i-j]){//放皇后 
				Q[++top]=j;//将放入皇后的列号入栈 
				col[j]=left[i+j]=right[N-1+i-j]=1;//说明已经放了皇后，标记列、斜线
				i++;//进入下一行 
				j=0;//对于下一行，j要从0开始遍历整行 
				break;//放好了皇后就跳出 
			}
		} 
		if(j==N){//如果j==8，说明一行跑完了 
			i--;//因为i行不能放，所以i要减一，回到其上一行，这样就可以进行下面步骤，抹掉当前行的皇后了
			j=Q[top--];//抹掉第i行的皇后
			col[j]=left[i+j]=right[N-1+i-j]=0;//重置0，表示此列、斜线无皇后
			j++;//跳过当前行 皇后，也就是抹掉了它，进而进行当前行下一个位置的判断 
		}
	}
}
int main()
{
	int i;
	Queen();
	for(i=0;i<N;i++){
		for(int j=0;j<N;j++){
		if(Q[i]==j){//皇后的位置 其中下标i为行数，Q[i]的值为对应的列数 
		printf("X  ");//标记皇后 
		}
		else{
			printf("0  ");
		} 
		}
		printf("\n");
	}
	return 0;
}*/

#include<stdio.h>
int col[8]={0};
int left[15]={0};
int right[15]={0};
int Q[8]={0};
int cnt=0;

void Print()
{
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
		if(Q[i]==j){//皇后的位置 其中下标i为行数，Q[i]的值为对应的列数 
		printf("X  ");//标记皇后 
		}
		else{
			printf("0  ");
		} 
		}
		printf("\n");
	}
}

void Queen(void)
{
	int top,i,j;
	i=0;
	top=-1;
	j=0;
	while(i>-1){
		for(;j<8;j++){//遍历i行的8列 
			if(!col[j]&&!left[i+j]&&!right[7+i-j]){//放皇后 
				Q[++top]=j;//将放入皇后的列号入栈 
				col[j]=left[i+j]=right[7+i-j]=1;//说明已经放了皇后，标记列、斜线
				i++;//进入下一行 
				j=0;//对于下一行，j要从0开始遍历整行 
				break;//放好了皇后就跳出 
			}
		} 
		if(j==8||top==7){//如果j==8，说明一行跑完了,top==7说明一组解已经求出来了 
			if(top==7){
				cnt++;
				Print();	
			}
			i--;//因为i行不能放，所以i要减一，回到其上一行，这样就可以进行下面步骤，抹掉当前行的皇后了
			j=Q[top--];//抹掉第i行的皇后
			col[j]=left[i+j]=right[7+i-j]=0;//重置0，表示此列、斜线无皇后
			j++;//跳过当前行 皇后，也就是抹掉了它，进而进行当前行下一个位置的判断 
		}
	}
}

int main()
{
	int i;
	Queen();
	printf("共有%d组解",cnt);
	return 0;
}



