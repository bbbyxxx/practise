package com.Fengkuangjava.分治法;

import java.util.Scanner;
import java.util.Stack;

//归并排序的思想是：将数组一分为二，然后对左边排序，再对右边排序
//然后左边又一分为二，然后重复上面过程，右边也一分为二，重复上面过程
public class 归并排序 {
    /**
     *
     * @param nums
     * @param L 左边
     * @param M 中间
     * @param R 右边
     */
   /* public static void Merage(int[] nums,int L,int M,int R){
        int leftSize = M - L;
        int rightSize = R - M + 1;
        int[] left = new int[leftSize];
        int[] right = new int[rightSize];
        int i = 0,j = 0,k = 0;

        //将左边的所有元素放入left数组中
        for (i = L; i < M; i++) {
            left[i-L] = nums[i];
        }
        //将右边的所有元素放入right数组中
        for (j = M; j <=R; j++) {
            right[j-M] = nums[j];
        }

        //合并排序两个数组
        i = 0;
        j = 0;
        k = L;
        while(i<leftSize&&j<rightSize){
            if (left[i]<right[j]){
                nums[k++]=left[i++];
            }else{
                nums[k++]=right[j++];
            }
        }

        while(i<leftSize){//左边数组未完
            nums[k++] = left[i++];
        }

        while(j<rightSize){//右边数组未完
            nums[k++] = right[j++];
        }
    }

    public static void mergeSort(int[] nums,int L,int R){
        if (L==R){
            return;
        }
        int M = (L+R)/2;
        mergeSort(nums,L,M);//左边
        mergeSort(nums,M+1,R);//右边
        Merage(nums,L,M+1,R);
    }*/

   public static void mergeSort(int[] nums,int L,int R) {
       if (L>=R){
           return;
       }
       int mid = (L + R) / 2;//划分区间
       mergeSort(nums, L, mid);//排序左区间
       mergeSort(nums, mid + 1, R);//排序右区间

       //排序
       int i = L, j = mid + 1;
       Stack<Integer> stack = new Stack<>();//定义一个栈
       while (i <=mid&& j<=R) {//排序并入栈
           if (nums[i] <= nums[j]) {
               stack.push(nums[i++]);
           } else {
               stack.push(nums[j++]);
           }
       }

       while (i <= mid) {//左数组没完
           stack.push(nums[i++]);
       }

       while (j <= R) {//右数组没完
           stack.push(nums[j++]);
       }

       for (int k = L,m = 0; m < stack.size();m++, k++) {
           nums[k] = stack.get(m);
       }
   }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度n：");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        mergeSort(nums,0,n-1);
        //输出
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]+" ");
        }
    }
}
