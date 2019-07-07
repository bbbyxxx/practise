package com.Fengkuangjava;

import java.util.Scanner;

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
 */
public class MaxSubArray {
    public static int maxSubArray(int[] nums) {
        /*int cnt,max=-2147483648;
        for (int i = 0; i < nums.length; i++) {
            cnt=0;
            for (int j = i; j < nums.length; j++) {
                cnt += nums[j];
                if(cnt>max){
                    max=cnt;
                }
            }
        }
        return max;*/
        int max = nums[0];
        int sum = 0;
        for (int n : nums) {
            sum += n;
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] t = ArrayScanfAndPrintf.way();
        System.out.println(maxSubArray(t));//pp.way返回数组
    }
}
