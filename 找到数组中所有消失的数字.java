package practice;

import javax.swing.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

        找到所有在 [1, n] 范围之间没有出现在数组中的数字。

        您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

        示例:

        输入:
        [4,3,2,7,8,2,3,1]

        输出:
        [5,6]

        来源：力扣（LeetCode）
*/
public class 找到数组中所有消失的数字 {
    public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        if (nums.length==0){
            return list;
        }
        int[] numbers = new int[nums.length+1];
        for (int i = 0; i < nums.length; i++) {
            numbers[nums[i]]++;
        }
        for (int j = 0; j < numbers.length; j++) {
            if (numbers[j]==0){
                list.add(j);
            }
        }
        list.remove(0);
        return list;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入数组长度：");
        int n = in.nextInt();
        System.out.println("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        List<Integer> list = findDisappearedNumbers(nums);
        for (int number:list
             ) {
            System.out.print(number+" ");
        }
    }
}
