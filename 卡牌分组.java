package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000

来源：力扣（LeetCode）
 */
public class 卡牌分组 {
    public static boolean hasGroupsSizeX(int[] deck) {
        if (deck.length<=1){
            return false;
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < deck.length; i++) {//得到最大值 为后面的最大长度
            if (max<deck[i]){
                max = deck[i];
            }
        }
        int[] nums = new int[max+1];
        int[] num = new int[max+1];
        int k = 0;
        for (int i = 0; i < deck.length; i++) {
            nums[deck[i]]++;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]!=0){
                num[k++] = nums[i];
            }
        }
        System.out.println(Arrays.toString(num));
        for (int i = 0; i < num.length-1; i++){
            if(num[i+1]==0){
                continue;
            }
            boolean x = judge(num[i],num[i+1]);
            if (x == false){
                return false;
            }
        }
        return true;
    }
    public static  boolean judge(int x , int y){
        int min = 0;
        if (x>y){
            min = y;
        }else{
            min = x;
        }
        for (int i = 2; i <=min; i++) {
            if (x%i==0&&y%i==0){
                return true;
            }
        }
        return  false;
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
        System.out.println( hasGroupsSizeX(nums));
    }
}
