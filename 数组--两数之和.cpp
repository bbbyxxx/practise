/*求两个数之和等于key
返回这两个数的下标  并且加过的数不能再使用 */
#include<bits/stdc++.h>
using namespace std;
void twoSum(int* nums, int numsSize, int target){
	int i,j;
	int *returna=(int *)malloc(sizeof(int)*numsSize);
	for(i=0;i<numsSize;i++){
		returna[i]=0;
	}
	for(i=0;i<numsSize-1;i++){
		for(j=i+1;j<numsSize;j++){
			if(nums[i]+nums[j]==target&&returna[i]<2&&returna[j]<2){
				returna[i]++;
				returna[j]++;
				cout<<i<<" "<<j<<endl;
			}
			else{
				continue;
			}
		}
	}
	free(returna);
}
int main()
{
	int n,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>key;
	twoSum(a,n,key);
	return 0;
}
