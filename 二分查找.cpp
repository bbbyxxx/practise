//���ֲ���
#include<bits/stdc++.h>
void sort(int a[],int n)
{
	int i,j,x;
	for(int i = 1;i<n;i++){
		x=a[i];
		for(j=i-1;j>=0&&a[j]>x;a[j+1]=a[j],j--);
		a[j+1] = x;
	}
}

int halfSearch(int a[],int low,int high,int key)
{
	sort(a,high-low+1);
	int mid;
	if(low<=high){
		mid = (low+high)/2;
		if(a[mid]==key){
			return mid;
		}else if(a[mid]<key){
			return halfSearch(a,mid+1,high,key);
		}else{
			return halfSearch(a,low,mid-1,key);
		}
	}
	else{
		return -1;
	}
}
int main()
{
	int n;
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	printf("����������Ԫ�أ�");
	int *a;
	a = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
	   scanf("%d",&a[i]);
	}
	printf("������keyֵ��");
	int key;
	scanf("%d",&key);
	printf("%d",halfSearch(a,0,n-1,key));
} 
