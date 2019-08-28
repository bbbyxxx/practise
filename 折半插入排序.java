package com.Fengkuangjava;

import java.util.Arrays;
import java.util.Scanner;

public class 折半插入排序 {
    public static void binsertSort(int[] nums){
        for (int i = 1; i < nums.length; i++) {
            int t = nums[i];
            int low = 0,high = i;
            while(low<=high){
                int mid = (low + high)/2;
                if (t<nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }//循环结束 high+1的位置即为要插入的位置
            int j;
            for (j = i-1; j >=high+1 ; j--) {//移动元素
                nums[j+1] = nums[j];
            }
            nums[j+1] = t;//将元素插入到正确位置
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int length = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = in.nextInt();
        }
        binsertSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
