package com.Fengkuangjava.分治法;

import java.util.Arrays;
import java.util.Scanner;

/*
快速排序的思想：以一个基准元素，以它为中心将数组分为左边全比它小，右边全比它大
然后递归判断其左边区间，重复上面过程，直到只有一个元素为止
 */
public class 快速排序 {
   public static void quickSort(int[] nums,int l,int r){
        if (l>=r){
            return;
        }
        int i = l;
        int j = r;
        int flag = nums[l];
        while(i<j){

            while(nums[j]>=flag&&i<j){//定位右边第一个要交换的元素
                j--;
            }

            int t;
            if (i<j) {
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
            while(nums[i]<=flag&&i<j){//定位左边第一个要交换的元素
                i++;
            }

            //交换
            if (i<j){
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;

            }
        }
           quickSort(nums,l,j);//排左边
           quickSort(nums,j+1,r);//排右边
    }

    /*public static void quickSort(int[] nums,int l,int r){
        if (l>=r){
            return;
        }
        int i = l-1,j = r+1,x = nums[l];
        while(i<j){

            do {
                j--;
            }while(nums[j]>x);

            do {
                i++;
            }while(nums[i]<x);

            if (i<j){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }else{//说明一趟已经排好了
                quickSort(nums,l,j);
                quickSort(nums,j+1,r);
            }
        }
    }*/

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] nums = {3,-2,5,8,8,-7,6,9};
        quickSort(nums,0,7);
        System.out.println(Arrays.toString(nums));
    }
}
