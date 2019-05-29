存在重复
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int singleNumber(int* nums, int numsSize){
	
	/*int i;
	for(i=0;i<numsSize;i++){
		b[abs(nums[i])]++;
	}
	for(i=0;i<numsSize;i++){
		if(b[abs(nums[i])]==1){
			return nums[i];
		}
	}
    return nums[numsSize-1];*/
    
    /*sort(nums,nums+numsSize);
    for(int i=0;i<numsSize-1;){
    	if(nums[i]==nums[i+1]){
    		i=i+2;
    	}
    	else{
    		return nums[i];
    	}
    }
    return nums[numsSize-1]; */
    
   /* C++，位运算，按位异或。

int a = 0, b = 5;
a = a ^ b;  // a = 5
a = a ^ b;  // a = 0
根据上述规律，即一个数b与初始为0的数a按位异或两次，a就会变成0。

同理，本题中数组nums中所有出现两次的数与初始为0的数a按位异或两次，a都会变成0。

所以最后a就会变成只与a按位异或一次的那个数。*/
	int t=0;
	for(int i=0;i<numsSize;i++){
		t^=nums[i];
	}
	return t;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<singleNumber(a,n);
	return 0;
}
