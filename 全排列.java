package 全排列;

import java.util.Arrays;
import java.util.Scanner;

/*
全排列的思想就是：每次将一个数字取出来放到最开始的位置
然后，对1~n-1进行全排列，然后范围逐渐缩小
 */
public class 全排列 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        System.out.print("请输入数组长度：");
        n = in.nextInt();
        int[] nums = new int[n];
        System.out.print("请输入数组元素:");
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        quanPaiLie(nums,0,n);//全排列
    }

    public static void quanPaiLie(int[] nums,int left,int right){
        if (left==right){//没元素可以交换，代表结束
            Print(nums);
        }
        for (int i = left; i < right; i++) {
            swap(nums,left,i);//依次将后面的元素换到初始位置
            quanPaiLie(nums,left+1,right);//递归调用，缩小范围
            swap(nums,i,left);//将原来的顺序复原
        }
    }

    public static void swap(int[] nums,int left,int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    public static void Print(int[] nums){
        System.out.println(Arrays.toString(nums));
    }
}
