//设有一个数据序列，查找一个连续子序列，其和值最大 
//1.0暴力 
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
    printf("最大值%d",max);
}


int main()
{
	int a[10] = {-1,12,-5,6,-4,-2,-6,-9,-1,-6};
	MaxSum(a,10);
	printf("%4d",max);
	printf("[%d,%d]",mi,mj);
	return 0;
}*/


//2.0利用额外空间保存区间和
/*#include<bits/stdc++.h>
int max = -2147483647;
int mi,mj;
int s[11];//长度多一个 0下标存0 

void MaxSum(int a[],int n)
{
	int i,j;
	for(i=1;i<n+1;i++){
		s[i]=s[i-1]+a[i-1];//将区间和放入s数组中 
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

//3.0分治法
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
        //如果当前序列只有一个元素
        return data[left];
    }
    int center = (left + right) / 2;//计算当前序列的分裂点
    int maxLeftSum = maxSumRec(data,left,center);//左二分 
    int maxRightSum = maxSumRec(data,center,right);//右二分 
    //计算左边界最大子序列和
    int leftBonderSum = 0;
    int maxLeftBonderSum = data[center-1];
    for (int i = center - 1; i >= left; i--){
        leftBonderSum += data[i];
        if (maxLeftBonderSum < leftBonderSum){
            maxLeftBonderSum = leftBonderSum;
        }
    }
    //计算右边界最大子序列和
    int rightBonderSum = 0;
    int maxRightBonderSum = data[center];
    for (int i = center; i < right; i++){
        rightBonderSum += data[i];
        if (maxRightBonderSum < rightBonderSum){
            maxRightBonderSum = rightBonderSum;
        }
    }
    //返回当前序列最大子序列和
    return getMaxNum(maxLeftBonderSum + maxRightBonderSum, maxLeftSum, maxRightSum);
}

int main()
{
	int a[10] = {-1,12,-5,6,-4,-2,-6,-9,-1,-6};
	printf("%4d",maxSumRec(a, 0, 9));
	return 0;
}

