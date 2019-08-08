package practice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1:

输入: [1, 2, 2, 3, 1]
输出: 2
解释:
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2:

输入: [1,2,2,3,1,4,2]
输出: 6
注意:

nums.length 在1到50,000区间范围内。
nums[i] 是一个在0到49,999范围内的整数。

来源：力扣（LeetCode）
 */
public class 数组的度 {
    public static int findShortestSubArray(int[] nums) {
        int[] big = new int[50000];
        for (int i = 0; i < nums.length; i++) {
            big[nums[i]]++;
        }
        int max = 0;
        for (int i = 0; i < 50000; i++) {//得到最大的度数
            if (big[i]>max){
                max = big[i];
            }
        }
        if (max==1){
            return 1;
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 50000; i++) {//得到与度数相同的数
            if (big[i] == max){
                list.add(i);
            }
        }
        int m = 0,min = Integer.MAX_VALUE;
        for (int i = 0;i<list.size();i++ ) {
            int number = list.get(i);
            for (int j = 0,k=nums.length-1;;) {
                if (nums[j]!=number){
                    j++;
                }
                if (nums[k]!=number){
                    k--;
                }
                if (nums[j]==number&&nums[k]==number){
                    m = k-j+1;
                    break;
                }
            }
            if (min>m){
                min = m;
            }
        }
        return min;
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
        System.out.println(findShortestSubArray(nums));
    }
}
