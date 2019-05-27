#include<bits/stdc++.h>
using namespace std;
void findDiagonalOrder(int **matrix,int M,int N){
		int i=0,j=0;
		int k=0;
		if(matrix==NULL||M*N==0){
			cout<<"error!";
		}
		for(i=0;i<M*N;i++){
			cout<<matrix[j][k]<<" ";
			if((j+k)%2==0){
				if(k==N-1){//向下走 
					j++;
				}
				else if(j==0){//向右走 
					k++;
				}
				else{//向右上走 
					j--;
					k++;
				}
			}
			else{
				 if(j==M-1){//向上走 
					k++; 
				}
				else if(k==0){//向下走 
					j++; 
				}
				else{//向左下走 
					j++;
					k--;
				}
			}
		}
}
int main()
{
	int i,j;
	int M,N;
	cin>>M>>N;
	//int **a=new int *[M];
	//a[0]=new int [M*N];
	int **a=(int **)malloc(sizeof(int *)*M);
	a[0]=(int *)malloc(sizeof(int)*(M*N));
	for(i=1;i<M;i++){
		a[i]=a[i-1]+N;
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cin>>a[i][j];
		}
	}
	findDiagonalOrder(a,M,N);
	return 0;
}

