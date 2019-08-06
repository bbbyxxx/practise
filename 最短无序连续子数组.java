package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

来源：力扣（LeetCode）
 */
public class 最短无序连续子数组 {
    public static int findUnsortedSubarray(int[] nums) {
       /* int high = 0;// 第一个大值不正确的索引
        int low = 1; // 第一个小值不正确的索引
        int maxValue = 0;// 记录从左到右的当前最大值
        int minValue = 0;// 记录从右到左的当前最小值
        for (int i = 0; i < nums.length; i++) {
            if (i == 0) {
                maxValue = nums[i];
            } else {
                if (nums[i] < maxValue) {
                    high = i;
                }
                maxValue = Math.max(maxValue, nums[i]);
            }
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i == nums.length - 1) {
                minValue = nums[i];
            } else {
                if (nums[i] > minValue) {
                    low = i;
                }
                minValue = Math.min(minValue, nums[i]);
            }
        }
        return high - low + 1;*/

        /*int length = nums.length;
        int low = length - 1;
        int high = 0;
        int max = nums[0];
        int min = nums[length-1];
        for (int i = 0;i < length;i++) {
            max = Math.max(nums[i],max);
            min = Math.min(nums[length-i-1],min);
            if (nums[i] < max) {
                high = i;
            }
            if (nums[length-i-1] > min) {
                low = length-i-1;
            }
        }
        if (low >= high) {
            return 0;
        }
        return high-low+1;*/

        int n1 = 0, n2 =0;
        int[] nums1 = Arrays.copyOf(nums,nums.length);
        Arrays.sort(nums1);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != nums1[i]){
                n1 = i;
                break;
            }
        }
        for (int j = nums.length-1; j >=0 ; j--) {
            if(nums[j] != nums1[j]){
                n2 = j;
                break;
            }
        }
        return n1==n2?0:n2-n1+1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int length = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println(findUnsortedSubarray(nums));
    }
}
