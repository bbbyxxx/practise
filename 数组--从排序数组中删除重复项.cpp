#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int* nums, int numsSize){
	int i=0,j;
	while(i<numsSize-1){
		j=i+1;
		if(nums[i]==nums[j]){
			for(j=i+1;j<numsSize-1;j++){
				nums[j]=nums[j+1];
			}
			numsSize--;
		}
			else{
				i++;
			}
	}
	return numsSize;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=removeDuplicates(a,n);
	for(int j=0;j<t;j++){
		cout<<a[j]<<" ";
	}
	return 0;
}
