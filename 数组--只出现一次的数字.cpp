�����ظ�
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��

ʾ�� 1:

����: [1,2,3,1]
���: true
ʾ�� 2:

����: [1,2,3,4]
���: false
ʾ�� 3:

����: [1,1,1,3,3,4,3,2,4,2]
���: true
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
    
   /* C++��λ���㣬��λ���

int a = 0, b = 5;
a = a ^ b;  // a = 5
a = a ^ b;  // a = 0
�����������ɣ���һ����b���ʼΪ0����a��λ������Σ�a�ͻ���0��

ͬ������������nums�����г������ε������ʼΪ0����a��λ������Σ�a������0��

�������a�ͻ���ֻ��a��λ���һ�ε��Ǹ�����*/
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
