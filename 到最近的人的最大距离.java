package practice;

import java.util.Scanner;

/*
在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。

至少有一个空座位，且至少有一人坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。

示例 1：

输入：[1,0,0,0,1,0,1]
输出：2
解释：
如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
因此，他到离他最近的人的最大距离是 2 。
示例 2：

输入：[1,0,0,0]
输出：3
解释：
如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
这是可能的最大距离，所以答案是 3 。
提示：

1 <= seats.length <= 20000
seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。

来源：力扣（LeetCode）

解题思路：

        记录开头连续0个数count1;
        记录结尾连续0个数count2;
        计算中间连续0个数的最大值countmax;
        count1、count2、(countmax+1)/2 三者中最大值即为结果.
                虽然代码中分三段循环，实际合起来只有一次完整循环，时间复杂度为O(n)
 */
public class 到最近的人的最大距离 {
    public static int maxDistToClosest(int[] seats) {
        int count1 = 0;
        int count2 = 0;
        int i = 0, j = seats.length-1;
        // count1记录开头连续0的个数
        while(seats[i] == 0){
            count1++;
            i++;
        }
        // count2记录结尾连续0的个数
        while(seats[j] == 0){
            count2++;
            j--;
        }
        // countmax记录从第一个1到最后一个1之间，连续0的最大值
        int countmid = 0, countmax = 0;
        for(int k = i+1; k <= j; k++){
            if(seats[k] == 0){
                countmid++;
            }else{
                countmax = Math.max(countmax, countmid);
                countmid = 0;
            }
        }
        // 返回count1, count2, (countmax+1)/2三者中最大值
        return Math.max(Math.max(count1, count2), (countmax+1)/2);
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
        System.out.println(maxDistToClosest(nums));
    }
}
