package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。

请你返回至少有多少个学生没有站在正确位置数量。该人数指的是：能让所有学生以 非递减 高度排列的必要移动人数。

 

示例：

输入：[1,1,4,2,1,3]
输出：3
解释：
高度为 4、3 和最后一个 1 的学生，没有站在正确的位置。
 

提示：

1 <= heights.length <= 100
1 <= heights[i] <= 100

来源：力扣（LeetCode）
 */
public class 高度检查器 {
    public static int heightChecker(int[] heights) {
        /*int[] nums = Arrays.copyOf(heights,heights.length);
        Arrays.sort(nums);
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;*/
        int[] arr = new int[101];
        for (int height : heights) {
            arr[height]++;
        }
        int count = 0;
        for (int i = 1, j = 0; i < arr.length; i++) {
            while (arr[i]-- > 0) {
                if (heights[j++] != i) count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n = in.nextInt();
        System.out.print("请输入数组元素:");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println(heightChecker(nums));
    }
}
