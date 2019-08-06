package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].

来源：力扣（LeetCode）
 */
public class 数组拆分1 {
    public int arrayPairSum(int[] nums) {
        int n = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i+=2) {
            n +=nums[i];
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n;
        while(true){
            n = in.nextInt();
            if (n%2==0){
                break;
            }
        }
        System.out.print("请输入数组元素");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println(new 数组拆分1().arrayPairSum(nums));
    }
}
