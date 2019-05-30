#include<bits/stdc++.h>
using namespace std;
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	/*int min,max,i,j,k=0;
	int *mi,*ma;
	if(nums1Size<nums2Size){
		min=nums1Size;
		mi=nums1;
		max=nums2Size;
		ma=nums2;
	}
	else{
		min=nums2Size;
		mi=nums2;
		max=nums1Size;
		ma=nums1;
	} 
	int c[max];
	int *returna=(int *)malloc(sizeof(int)*min);
	for(i=0;i<min;i++){
		for(j=0;j<max;j++){
			if(mi[i]==ma[j]&&c[j]!=1){
				c[j]=1;
				returna[k++]=mi[i];
				break;
			}
		}
	}
	*returnSize=k;
	return  returna;*/
	int i=0,j=0,k=0;
	sort(nums1,nums1+nums1Size);
	sort(nums2,nums2+nums2Size);
	int *m=(int *)malloc(sizeof(int)*(nums1Size+nums2Size));
	while(i<nums1Size&&j<nums2Size){//谁小谁加  一样则放入新数组中 
		if(nums1[i]<nums2[j]){
			i++;
		}
		else if(nums1[i]>nums2[j]){
			j++;
		}
		else{
			m[k++]=nums1[i];
			i++;
			j++;
		}
	}
	*returnSize=k;
	return m;
}
int main()
{
	int n1,n2,t=0,i,j;
	cin>>n1>>n2;
	int a[n1];
	int b[n2];
	int *m;//m指向新数组 
	for(i=0;i<n1;i++){
		cin>>a[i];
	}
	for(j=0;j<n2;j++){
		cin>>b[j];
	}
	m=intersect(a,n1,b,n2,&t);
	for(i=0;i<t;i++){
		cout<<m[i]<<" ";
	}
	return 0;
}
