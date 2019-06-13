 /*旋转图像
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]*/


/*
	先交换四个顶点的值，然后收缩继续交换相应位置的值 
*/
#include<stdio.h>
void rotate(int** matrix, int matrixSize){
	int i=0;
	int j=matrixSize-1;
	while(i<=j){
		int m=i;
		int n=j;
		while(m!=j){
		int t;
		t=matrix[i][m];//存入行第一个未交换元素 
		matrix[i][m]=matrix[n][i];//存入左下元素 
		matrix[n][i]=matrix[j][n];//存入右下元素 
		matrix[j][n]=matrix[m][j];//存入右上元素 
		matrix[m][j]=t;//存入行第一个未交换元素 
		m++;
		n--;
		}
		i++;
		j--;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int *a[n];
	int b[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
	rotate(a,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
