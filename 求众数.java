package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
 */
public class 求众数 {
    public static Scanner in = new Scanner(System.in);
    public static int majorityElement(int[] nums) {
        /*只适合正整数
        int max=0,t=0;
        int[] cnt = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            cnt[nums[i]%nums.length]++;
            if(cnt[nums[i]%nums.length]>max){
                max=cnt[nums[i]%nums.length];
                t=nums[i];
            }
        }
        if(max>nums.length/2){
            return t;
        }
        else{
            return 0;
        }*/
        int cnt = 0,max = 0,t=1;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length-1 ; i++) {
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt>max){
                max=cnt;
                t=nums[i];
            }
        }
        if(nums.length==1){
            t=nums[0];
        }
        return max+1>nums.length/2? t:0;
    }

    public static void main(String[] args) {
        int n;
        System.out.print("请输入数组的长度：");
        n = in.nextInt();
        int[] nums = new int[n];
        System.out.print("请输入数组元素:");
        for (int i = 0; i < nums.length ; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println("众数为： "+majorityElement(nums));
    }

}
