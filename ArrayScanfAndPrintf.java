package com.Fengkuangjava;

import java.util.Scanner;

public class ArrayScanfAndPrintf {
    private static int n;
    private static int[] nums;
    public static Scanner in = new Scanner(System.in);
    public static int[] way() {
        System.out.print("请输入数组长度：");
        n = in.nextInt();
        nums = new int[n];
        System.out.print("请输入数组元素：");
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        return nums;
    }
    public static int getN(){
        return n;
    }
}
