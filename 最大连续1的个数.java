package practice;

import java.util.Scanner;

/*
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。

来源：力扣（LeetCode）
 */
public class 最大连续1的个数 {
    private static Scanner in = new Scanner(System.in);
    public static int findMaxConsecutiveOnes(int[] nums) {
        /*int cnt=1;
        int max=Integer.MIN_VALUE;
        for (int i = nums.length-1; i >0; i--) {
            if(nums[i]==nums[i-1]&&nums[i]==1){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(max<cnt){
                max=cnt;
            }
        }
        return max==Integer.MIN_VALUE?1:max;*/
        int max = 0;
        int count = 0;
        for(int num:nums){
            if(num == 1)
                count++;
            else{
                if(count>max){
                    max = count;
                }
                count = 0;
            }
        }
        return max>count?max:count;
    }

    public static void main(String[] args) {
        int n = in.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println(findMaxConsecutiveOnes(nums));
    }
}
