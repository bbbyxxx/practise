package com.Fengkuangjava;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
 */
public class RemoveElement {
    private static Scanner in = new Scanner(System.in);//默认default作用域
    public static int removeElement(int[] nums, int val) {
        /*int i=-1;
        int tmp=0;
        int count=0;
        boolean lock =false;
        for(int j =0;j<nums.length;j++) {
            if(nums[j]==val&&!lock) {
                i=j;
                lock=true;
            }else {
                if(i>=0&&nums[i]!=nums[j]) {
                    tmp=nums[j];
                    nums[j]=nums[i];
                    nums[i]=tmp;
                    j=i;
                    lock=false;
                }
            }
            if(nums[j]!=val) {
                count++;
            }
        }
        return count;*/
        int num = 0;
        for (int i = 0; i < nums.length; ++i){
            if (nums[i] != val){
                nums[num++] = nums[i];
            }
        }
        return num;
    }
    public static void main(String[] args){
        int val;
        System.out.print("请输入数组长度n：");
        int n=in.nextInt();
        int[] nums = new int[n];
        System.out.print("请输入数组元素：");
        for (int i = 0; i < n ; i++) {
            nums[i]=in.nextInt();
        }
        System.out.print("请输入要删除的值：");
        val=in.nextInt();
        int length=removeElement(nums,val);//返回新长度
        System.out.println("新长度为："+length);
       for (int i = 0; i < length; i++) {
            System.out.print(nums[i]);
        }
    }
}
