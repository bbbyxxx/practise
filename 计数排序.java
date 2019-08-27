package com.Fengkuangjava;
/*
计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键，存储在额外的空间中，
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定的范围。
 */
import java.util.Arrays;
import java.util.Scanner;
//给定10^7个数，每个数在0~10^6之间
public class 计数排序 {
    public static void countingSort(int[] nums){
        //找出nums数组中的最大值
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (max < nums[i]){
                max = nums[i];
            }
        }
        //创建计数数组
        int[] cnt = new int[max+1];
        for (int i = 0; i < nums.length; i++) {
            cnt[nums[i]]++;
        }
        int k = 0;
        for (int i = 0; i < max+1; i++) {
            while(cnt[i]!=0){//计数数组中的数没用完
                nums[k++] = i;
                cnt[i]--;
            }
        }

    }
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        countingSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
