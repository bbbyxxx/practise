package practict2;

import java.util.Scanner;

/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。


图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

来源：力扣（LeetCode）
 */
public class 盛最多水的容器 {
    public static int maxArea(int[] height) {
       /* int len = height.length;
        int max = Integer.MIN_VALUE;
        int area = 0;
        for (int i = 0; i < len -1; i++) {
            for (int j = i+1; j < len; j++) {
                area = Math.min(height[i],height[j]) * (j-i);
                if (max<area){
                    max = area;
                }
            }
        }
        return max;*/

       int i= 0;
       int j = height.length-1;
       int max = Integer.MIN_VALUE;
       while(i<j){
           int area = Math.min(height[i],height[j]) * (j-i);
           if (max<area){
               max = area;
           }
           if (height[i]<height[j]){
               i++;
           }else{
               j--;
           }
       }
       return max;
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
        System.out.println(maxArea(nums));
    }
}
