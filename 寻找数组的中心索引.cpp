����һ���������͵����� nums�����дһ���ܹ��������顰�����������ķ�����

���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�

������鲻����������������ô����Ӧ�÷��� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ����

ʾ�� 1:

����: 
nums = [1, 7, 3, 6, 5, 6]
���: 3
����: 
����3 (nums[3] = 6) �������֮��(1 + 7 + 3 = 11)�����Ҳ���֮��(5 + 6 = 11)��ȡ�
ͬʱ, 3 Ҳ�ǵ�һ������Ҫ�������������
ʾ�� 2:

����: 
nums = [1, 2, 3]
���: -1
����: 
�����в��������������������������
˵��:

nums �ĳ��ȷ�ΧΪ [0, 10000]��
�κ�һ�� nums[i] ������һ����Χ�� [-1000, 1000]��������

#include<bits/stdc++.h>
using namespace std;
int pivotIndex(int* nums, int numsSize){
	int i,cnt1=0,cnt2=0;
	for(i=0;i<numsSize;i++){
		cnt1+=nums[i];
	}
	for(i=0;i<numsSize;i++){
		if(cnt2*2+nums[i]==cnt1){
			return i;
		}
        cnt2+=nums[i];
	}
	return -1;
}
int main()
{
	int n;//���鳤�� 
	cin>>n;
	int *nums;
	nums=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	} 
	cout<<pivotIndex(nums,n);
	return 0;
}
