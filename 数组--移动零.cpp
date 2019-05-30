 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(int* nums, int numsSize){
	
	/*if(nums == NULL || numsSize == 0){
            return;
        }  
	int i=0,j;
	while(i<numsSize){
		if(nums[i]==0){
			for(j=i;j<numsSize-1;j++){
				nums[j]=nums[j+1];
			}
			nums[j]=0;
			numsSize--;
		}
		else{
			i++;
		}
	}*/
	
	/*if(nums == NULL || numsSize == 0){
            return;
        }  
    int i = 0,j = 0;
    for(i = 0 ; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }
    while(j < numsSize)
    {
        nums[j++] = 0;
    }
    return nums;*/
    
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	moveZeroes(a,n);
	for(int j=0;j<n;j++){
		cout<<a[j]<<" ";
	}
	return 0;
}
