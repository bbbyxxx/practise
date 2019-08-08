package practice;

import java.util.Scanner;

/*
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。

来源：力扣（LeetCode）
 */
public class 最长连续递增序列 {
    public static int findLengthOfLCIS(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int cnt=1,max=1;
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] < nums[i+1]){
                cnt++;
            }else{
                cnt = 1;
            }
            if (max<cnt){
                max = cnt;
            }
        }
        return max;
        /*if(arr == null || arr.length == 0) return 0;
        int count = 1;
        int result = 0;
        for(int i = 1; i < arr.length; i++){
            if(arr[i] > arr[i-1])
                count++;
            else{
                result = Math.max(count, result);
                count = 1;
            }
        }
        return Math.max(result,count);*/
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n =in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println(findLengthOfLCIS(nums));
    }
}
