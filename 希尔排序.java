package com.Fengkuangjava;

import java.util.Arrays;
import java.util.Scanner;

public class 希尔排序 {//缩小增量法
    public static void shellSort(int[] nums){
        int step = nums.length/2;
        for (int i = step; i > 0; i /= 2) {//增量序列
            for (int j = i; j < nums.length; j++) {//直接插入排序
                int t = nums[j];
                int k;
                for (k = j; k >=i&&nums[k-i]>t ; nums[k]=nums[k-i],k -=i);
                    nums[k] = t;
                }
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
        shellSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
