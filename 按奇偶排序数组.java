package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

来源：力扣（LeetCode）
 */
public class 按奇偶排序数组 {
    public static int[] sortArrayByParity(int[] A) {
        int i = 0;
        int j = A.length-1;
        while(i<j){
            if (A[i]%2==0){
                i++;
            }
            if (A[j]%2 == 1){
                j--;
            }
            if (A[i]%2 == 1 && A[j]%2 == 0&&i<j){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }
        return A;
    }

    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n  = in.nextInt();
        System.out.print("请输入人数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        nums = sortArrayByParity(nums);
        System.out.println(Arrays.toString(nums));
    }
}
