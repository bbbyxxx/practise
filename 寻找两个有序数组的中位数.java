package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
 */
public class 寻找两个有序数组的中位数 {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        /*double cnt = 0;
        int[] nums = new int[nums1.length+nums2.length];
        int i;
        for (i = 0; i < nums1.length; i++) {
            nums[i] = nums1[i];
        }
        for (int j = 0; j < nums2.length; j++) {
            nums[i++] = nums2[j];
        }
        Arrays.sort(nums);
        if (nums.length%2==0){
            int t = nums.length/2;
            cnt = (nums[t]+nums[t-1])/2.0;
        }else{
            cnt = nums[nums.length/2];
        }
        return cnt;*/

        double cnt = 0;
        int[] nums = new int[nums1.length+nums2.length];
        int k = 0;
        int i = 0;
        int j = 0;
        while(i<nums1.length&&j<nums2.length){
            if (nums1[i]>nums2[j]){
                nums[k++] = nums2[j++];
            }else{
                nums[k++] = nums1[i++];
            }
        }
        if (i!=nums1.length){//nums1数组没完
            while(i<nums1.length) {
                nums[k++] = nums1[i++];
            }
        }else{
            while(j<nums2.length) {
                nums[k++] = nums2[j++];
            }
        }
        if (nums.length%2==0){
            int t = nums.length/2;
            cnt = (nums[t]+nums[t-1])/2.0;
        }else{
            cnt = nums[nums.length/2];
        }
        return  cnt;
    }
    public static void main(String[] args) {
       Scanner in =new Scanner(System.in);
       int[] nums1 = {2,2,2,2};
       int[] nums2 = {2,2,2};
        System.out.println(findMedianSortedArrays(nums1,nums2));
    }
}
