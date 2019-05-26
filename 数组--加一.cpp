/*定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。*/
#include<bits/stdc++.h>
using namespace std;
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i,j,t;//t为进位 
    int *return_array=(int *)malloc(sizeof(int)*(digitsSize+1));
    if(digits[digitsSize-1]==9){
    	digits[digitsSize-1]=0;
    	t=1;
    }
    else{
    	digits[digitsSize-1]=digits[digitsSize-1]+1;
    	t=0;
    }
    for(i=digitsSize-2;i>=0;i--){
    	if(digits[i]+t>=10){
    		digits[i]=(digits[i]+t)%10;
    		t=1;
    	}
    	else{
    		digits[i]=digits[i]+t; 
    		t=0;
    		break;
    	}
    }
    if(t==1){
    	return_array[0]=1;
    	for(i=0;i<digitsSize;i++){
    		return_array[i+1]=digits[i];
    	}
    	*returnSize=digitsSize+1;
    	return return_array;
    }
    else{
    	free(return_array);
    	return digits;
    }
}
int main()
{
	int n,i;
	cin>>n;
	int *a;
	int b=n;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int *c=plusOne(a,n,&b);
	for(i=0;i<b;i++){
		cout<<c[i];
	}
	return 0;
}




