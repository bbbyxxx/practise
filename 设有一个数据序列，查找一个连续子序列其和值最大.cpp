//����һ���������У�����һ�����������У����ֵ��� 
//1.0���� 
/*#include<bits/stdc++.h>
int max = -2147483647;
int mi,mj;

void MaxSum(int a[],int n)
{
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			int sum = 0; 
			for(int k = i;k<=j;k++){
				sum += a[k];
			}
			if(sum>max){
				max = sum;
				mi = i;
				mj = j;
			}
		}
	}
}

/*1.2void maxSum(int data[],int len){
    int max = data[0];
    for (int i = 0; i < len; i++){
        int goal = 0;
        for (int j = i; j < len; j++){
            goal += data[j];
            if (goal > max){
                max = goal;
            }
        }
    }
    printf("���ֵ%d",max);
}


int main()
{
	int a[10] = {-1,12,-5,6,-4,-2,-6,-9,-1,-6};
	MaxSum(a,10);
	printf("%4d",max);
	printf("[%d,%d]",mi,mj);
	return 0;
}*/


//2.0���ö���ռ䱣�������
/*#include<bits/stdc++.h>
int max = -2147483647;
int mi,mj;
int s[11];//���ȶ�һ�� 0�±��0 

void MaxSum(int a[],int n)
{
	int i,j;
	for(i=1;i<n+1;i++){
		s[i]=s[i-1]+a[i-1];//������ͷ���s������ 
	}
	for(i=1;i<n+1;i++){
		for(j=i;j<n+1;j++){
			if(s[j]-s[i-1]>max){
				max = s[j]-s[i-1];
				mi = i-1;
				mj = j-1;
			}
		}
	}
}

int main()
{
	int a[10] = {-1,12,-5,6,-4,-2,-6,-9,-1,-6};
	MaxSum(a,10);
	printf("%4d",max);
	printf("[%d,%d]",mi,mj);
	return 0;
} */

//3.0���η�
#include<bits/stdc++.h>
int getMaxNum(int a,int b,int c){
    if (a > b&&a > c){
        return a;
    }
    if (b > a&&b > c){
        return b;
    }
    return c;
}
int maxSumRec(int data[], int left, int right){
    if (right - left == 1){
        //�����ǰ����ֻ��һ��Ԫ��
        return data[left];
    }
    int center = (left + right) / 2;//���㵱ǰ���еķ��ѵ�
    int maxLeftSum = maxSumRec(data,left,center);//����� 
    int maxRightSum = maxSumRec(data,center,right);//�Ҷ��� 
    //������߽���������к�
    int leftBonderSum = 0;
    int maxLeftBonderSum = data[center-1];
    for (int i = center - 1; i >= left; i--){
        leftBonderSum += data[i];
        if (maxLeftBonderSum < leftBonderSum){
            maxLeftBonderSum = leftBonderSum;
        }
    }
    //�����ұ߽���������к�
    int rightBonderSum = 0;
    int maxRightBonderSum = data[center];
    for (int i = center; i < right; i++){
        rightBonderSum += data[i];
        if (maxRightBonderSum < rightBonderSum){
            maxRightBonderSum = rightBonderSum;
        }
    }
    //���ص�ǰ������������к�
    return getMaxNum(maxLeftBonderSum + maxRightBonderSum, maxLeftSum, maxRightSum);
}

int main()
{
	int a[10] = {-1,12,-5,6,-4,-2,-6,-9,-1,-6};
	printf("%4d",maxSumRec(a, 0, 9));
	return 0;
}

