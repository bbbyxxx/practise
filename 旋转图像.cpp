 /*��תͼ��
����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��

��ͼ��˳ʱ����ת 90 �ȡ�

˵����

�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��

ʾ�� 1:

���� matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

ԭ����ת�������ʹ���Ϊ:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
ʾ�� 2:

���� matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

ԭ����ת�������ʹ���Ϊ:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]*/


/*
	�Ƚ����ĸ������ֵ��Ȼ����������������Ӧλ�õ�ֵ 
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
		t=matrix[i][m];//�����е�һ��δ����Ԫ�� 
		matrix[i][m]=matrix[n][i];//��������Ԫ�� 
		matrix[n][i]=matrix[j][n];//��������Ԫ�� 
		matrix[j][n]=matrix[m][j];//��������Ԫ�� 
		matrix[m][j]=t;//�����е�һ��δ����Ԫ�� 
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
