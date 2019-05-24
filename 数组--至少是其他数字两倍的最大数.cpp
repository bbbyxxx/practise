#include<bits/stdc++.h>
using namespace std;
int dominantIndex(int* nums, int numsSize){
	int max=0,i,t,cnt=0;
	if(numsSize==1){
		return 0;
	}
	for(i=0;i<numsSize;i++){
		if(nums[i]>max){
			max=nums[i];
			t=i;
		}
	}
	for(i=0;i<numsSize;i++){
		if(nums[i]==max&&cnt<2){
			cnt++;
			continue;
		}
		if(cnt==2||nums[i]*2>max){
			break;
		}
	}
	if(i!=numsSize){
		t=-1;
	}
	return t;
}
int main()
 {
 	int n;
 	cin>>n;
 	int *a;
 	a=(int *)malloc(sizeof(int)*n);
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}
 	int t=dominantIndex(a,n);
 	cout<<t;
 	return 0;
}
