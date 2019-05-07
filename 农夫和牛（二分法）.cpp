/*农夫 John 建造了一座很长的畜栏，它包括N (2 <= N <= 100,000)个隔间，
这些小隔间依次编号为x1,...,xN (0 <= xi <= 1,000,000,000).
但是，John的C (2 <= C <= N)头牛们并不喜欢这种布局，而且几头牛放在一个隔间里，
他们就要发生争斗。为了不让牛互相伤害。John决定自己给牛分配隔间，
使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是什么呢？

先得到排序后的隔间坐标x0,…xN-1
在[L,R]内用二分法尝试“最大最近距离”D=(L+R)/2(L,R初值为[1,1000000000/C])
若D可行，则记住该D，然后在新[L,R]中继续尝试(L=D+1)
若D不可行，则在新[L,R]中继续尝试(R=D-1)*/
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
	cout<<"请输入隔间数N和牛的头数C：";
	cin>>N>>C;
	int a[1000];
	cout<<"请输入每个牛的隔间号坐标：";
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
