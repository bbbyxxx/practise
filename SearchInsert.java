package com.Fengkuangjava;

import java.util.Scanner;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
 */
public class SearchInsert {
    public static Scanner in = new Scanner(System.in);
    public static int searchInsert(int[] nums, int target) {
        int t=0;
        for (int i = 0; i < nums.length; i++) {//找到就跳出循环，没找到i跑到nums.length
            if(nums[i]==target){
                t=i;//存储下标值
                break;
            }
        }
        if(t==0){//t==0说明数组中没有要找的元素
            int j;
            for (j = 0; j < nums.length ; j++) {
                if(nums[j]>=target){
                    t=j;
                    break;
                }
            }
            if(j==nums.length){
                t=j;
            }
        }
        return t;
    }
    public static void main(String[] args) {
        int n,key;
        System.out.print("请输入数组长度:");
        n = in.nextInt();
        int[] nums = new int[n];
        System.out.print("请输入数组元素：");
        for (int i = 0; i < nums.length; i++) {
            nums[i]=in.nextInt();
        }
        System.out.print("请输入要查找的值：");
        key=in.nextInt();
        System.out.println(searchInsert(nums,key));
    }
}
