//回朔法--八皇后问题 
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
	printf("\n"); 
}

void Queen(int i)
{
	/*if(i>7){
				cnt++;
				Print();
	} 
	else{
	for(int j=0;j<8;j++){
		if(!left[i+j]&&!right[7+i-j]&&!col[j]){
			Q[i]=j;//放皇后
			left[i+j]=1;//标记当前列，左斜线，右斜线 
			right[i+7-j]=1;//标明已有皇后 
			col[j]=1;
			Queen(i+1);
						//抹掉皇后 ，这里j已经进入到下一次循环了，所以相当于抹掉了皇后 
			left[i+j]=0;//标记当前列，左斜线，右斜线 
			right[i+7-j]=0;//标明皇后已抹去 
			col[j]=0;
		}
	}
 }*/
 
	for(int j=0;j<8;j++){
		if(!left[i+j]&&!right[7+i-j]&&!col[j]){
			Q[i]=j;//放皇后
			left[i+j]=1;//标记当前列，左斜线，右斜线 
			right[i+7-j]=1;//标明已有皇后 
			col[j]=1;
			if(i<7){
			Queen(i+1);
		}
			else{
				cnt++;
				Print();
			}
						//抹掉皇后 ，这里j已经进入到下一次循环了，所以相当于抹掉了皇后 
			left[i+j]=0;//标记当前列，左斜线，右斜线 
			right[i+7-j]=0;//标明皇后已抹去 
			col[j]=0;
		}
	}
}

int main()
{
	Queen(0);
	printf("总共有%d组解！",cnt);
	return 0;
	
}
