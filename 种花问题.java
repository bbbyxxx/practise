package practice;

import java.util.Scanner;

/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
注意:

数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。

来源：力扣（LeetCode）
 */
public class 种花问题 {
    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        /*if (flowerbed.length>=3) {
            for (int i = 0; i < flowerbed.length; i++) {
                if (n == 0){
                    break;
                }
                if (i == 0 && flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i > 0  && i< flowerbed.length - 1&& flowerbed[i] == flowerbed[i - 1] && flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i == flowerbed.length - 1 && flowerbed[i] == flowerbed[i - 1] && flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }else{
            if(flowerbed.length==1&&flowerbed[0]==0&&n==1){
                n=0;
            }else if(flowerbed.length == 2&&flowerbed[0]==0&&flowerbed[1]==0&&n==1){
                n=0;
            }
        }
        return n == 0?true:false;*/
        int len = flowerbed.length;
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 1) continue;
            int pre = i == 0 ? 0 : flowerbed[i - 1];//获取当前位置前一个位置值 或 当前值（即0值）
            int next = i == len - 1 ? 0 : flowerbed[i + 1];//获取当前位置下一个位置值 或当前值（即0值）
            if (pre == 0 && next == 0) {
                n--;
                flowerbed[i] = 1;
            }

        }
        return n <= 0;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入n：");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.print("请输入cnt：");
        int cnt = in.nextInt();
        System.out.println(canPlaceFlowers(nums,cnt));
    }
}
