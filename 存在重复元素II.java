package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

来源：力扣（LeetCode）
 */
public class 存在重复元素II {
    private static Scanner in =new Scanner(System.in);
    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        boolean flag = true;
        for (int i = 0; i < nums.length-1&&flag; i++) {
            for (int j = i+1; j < nums.length&&flag; j++) {
                if(nums[i]==nums[j]&&Math.abs(i-j)<=k){
                    flag=false;
                }
            }
        }
        return flag==true?false:true;
    }

    public static void main(String[] args) {
        int key;
        ArrayScanfAndPrintf pp = new ArrayScanfAndPrintf();
        //System.out.println(Arrays.toString(pp.nums)+"   "+pp.n);
        System.out.print("请输入key值：");
        key = in.nextInt();
        System.out.println(containsNearbyDuplicate(pp.nums,key));
    }
}
