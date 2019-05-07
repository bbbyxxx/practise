/*ũ�� John ������һ���ܳ���������������N (2 <= N <= 100,000)�����䣬
��ЩС�������α��Ϊx1,...,xN (0 <= xi <= 1,000,000,000).
���ǣ�John��C (2 <= C <= N)ͷţ�ǲ���ϲ�����ֲ��֣����Ҽ�ͷţ����һ�������
���Ǿ�Ҫ����������Ϊ�˲���ţ�����˺���John�����Լ���ţ������䣬
ʹ������ͷţ֮�����С���뾡���ܵĴ���ô�����������С������ʲô�أ�

�ȵõ������ĸ�������x0,��xN-1
��[L,R]���ö��ַ����ԡ����������롱D=(L+R)/2(L,R��ֵΪ[1,1000000000/C])
��D���У����ס��D��Ȼ������[L,R]�м�������(L=D+1)
��D�����У�������[L,R]�м�������(R=D-1)*/
#include<bits/stdc++.h>
using namespace std;
int BinaryD(int a[],int mid,int N,int C)
{
	int cnt=1;
	int cur=a[0];
	int i;
	for(i=1;i<N;i++){
		if(a[i]-cur>=mid){
			cnt++;
			cur=a[i];
			if(cnt>=C){
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int N,C,i,L,R;
	cout<<"�����������N��ţ��ͷ��C��";
	cin>>N>>C;
	int a[1000];
	cout<<"������ÿ��ţ�ĸ�������꣺";
	for(i=0;i<N;i++){
	cin>>a[i]; 
	}
	sort(a,a+N);
	L=0;
	R=a[N-1]-a[0];
	while(L<=R){
		int mid=L+(R-L)/2;
		if(BinaryD(a,mid,N,C)){
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	cout<<L-1;
	return 0; 
}
