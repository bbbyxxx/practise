package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
 */
public class 缺失数字 {
    private static Scanner in = new Scanner(System.in);
    public static int missingNumber(int[] nums) {
        /*int i;
        Arrays.sort(nums);
        for (i = 0; i < nums.length&&nums[i]==i; i++);
        return i;*/

        /*int num=0;
        int i;
        for(i=0;i<nums.length;i++){
            num+=i;
            num-=nums[i];
        }
        return num+i;*/
        int res=nums.length;
        for(int i=0;i<nums.length;i++){
            res^=nums[i];
            res^=i;
        }
        return res;
    }

    public static void main(String[] args) {
        int n;
        System.out.print("请输入数组长度：");
        n=in.nextInt();
        int[] nums = new int[n];
        System.out.print("请输入数组元素值：");
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println("缺省的数字为："+missingNumber(nums));
    }
}
