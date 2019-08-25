package practict2;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
 */
public class 最接近的三数之和 {
    public static int threeSumClosest(int[] nums, int target) {
       /*
       if (nums.length<3||nums==null){
            return 0;
        }
        int rt = Integer.MAX_VALUE;
        int tt = 0;//返回的和
        int cnt = 0;
        for (int i = 0; i < nums.length-2; i++) {
            for (int j = i+1; j < nums.length-1; j++) {
                for (int k = j+1; k < nums.length; k++) {
                    cnt = nums[i] + nums[j] +nums[k];
                     if (Math.abs(cnt-target)<rt){
                        rt = Math.abs(cnt-target);
                        tt = cnt;
                    }
                }
            }
        }
        return tt;
        */

       /*
       标签：排序和双指针
本题目因为要计算三个数，如果靠暴力枚举的话时间复杂度会到 O(n^3)O(n
3
 )，需要降低时间复杂度
首先进行数组排序，时间复杂度 O(nlogn)O(nlogn)
在数组 nums 中，进行遍历，每遍历一个值利用其下标i，形成一个固定值 nums[i]
再使用前指针指向 start = i + 1 处，后指针指向 end = nums.length - 1 处，也就是结尾处
根据 sum = nums[i] + nums[start] + nums[end] 的结果，判断 sum 与目标 target 的距离，如果更近则更新结果 ans
同时判断 sum 与 target 的大小关系，因为数组有序，如果 sum > target 则 end--，如果 sum < target 则 start++，如果 sum == target 则说明距离为 0 直接返回结果
整个遍历过程，固定值为 n 次，双指针为 n 次，时间复杂度为 O(n^2)O(n
2
 )
总时间复杂度：O(nlogn) + O(n^2) = O(n^2)O(nlogn)+O(n
2
 )=O(n
2
 )

        */
        if (nums.length<3||nums==null){
            return 0;
        }
        Arrays.sort(nums);
        int rt = Integer.MAX_VALUE;
        int tt = 0;//返回的和
        for (int i = 0; i < nums.length; i++) {
            int l = i+1;
            int r = nums.length-1;
            while(l<r){
                int cnt = nums[i] + nums[l] +nums[r];
                if (Math.abs(cnt-target)<rt){
                    rt = Math.abs(cnt-target);
                    tt = cnt;
                }
                if (cnt-target>0){
                    r--;
                }else if (cnt-target<0){
                    l++;
                }else{
                    return cnt;
                }
            }
        }
        return tt;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.print("请输入目标值:");
        int key = in.nextInt();
        System.out.println(threeSumClosest(nums,key));
    }
}
