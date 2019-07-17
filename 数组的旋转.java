package com.xzy;

import jdk.internal.dynalink.beans.StaticClass;

import java.util.Arrays;
import java.util.Scanner;

/*
2、把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
public class 数组的旋转 {
    private static Scanner in = new Scanner(System.in);
    public static void exchangenums(int[] nums){
        int t=0,flag=0;//flag用于寻找要前移的下标
        for (int i = 0; i < nums.length-1&&nums[i]<nums[i+1];flag=nums.length-1-(i+1),i++);
        for (int i = 0,j = nums.length-1; i <j; i++,j--) {//逆置数组
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        for (int j = 0,k=flag-1; j < k; j++,k--) {//逆置前flag元素
            t=nums[j];
            nums[j]=nums[k];
            nums[k]=t;
        }
        for (int k = flag,m=nums.length-1; k < m; k++,m--) {//逆置后flag元素
            t=nums[k];
            nums[k]=nums[m];
            nums[m]=t;
        }
    }

    public static void Print(int[] nums){
        System.out.println(Arrays.toString(nums));
    }

    public static void main(String[] args) {
        System.out.print("请输入数组长度");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        exchangenums(nums);
        Print(nums);
    }
}
