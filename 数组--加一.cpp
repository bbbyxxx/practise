/*��һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

ʾ�� 1:

����: [1,2,3]
���: [1,2,4]
����: ���������ʾ���� 123��
ʾ�� 2:

����: [4,3,2,1]
���: [4,3,2,2]
����: ���������ʾ���� 4321��*/
#include<bits/stdc++.h>
using namespace std;
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i,j,t;//tΪ��λ 
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




