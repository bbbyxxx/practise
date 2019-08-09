package practice;

import java.util.Scanner;

/*
有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。

现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

示例 1:

输入:
bits = [1, 0, 0]
输出: True
解释:
唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
示例 2:

输入:
bits = [1, 1, 1, 0]
输出: False
解释:
唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
注意:

1 <= len(bits) <= 1000.
bits[i] 总是0 或 1.

来源：力扣（LeetCode）
 */
public class one比特与two比特字符 {
    public static boolean isOneBitCharacter(int[] bits) {
        /*if (bits.length == 0){
            return false;
        }
        if (bits.length == 1){
            if (bits[0] == 0){
                return true;
            }else{
                return false;
            }
        }
        if (bits[0] == 1&& bits.length==2){
            return false;
        }else if (bits[0]==0 && bits.length==2){
            return true;
        }
        int i= 0;
        for (i = 0; i < bits.length; i++) {
            if (i==bits.length-1){
                break;
            }
            if (bits[i]==bits[i+1]&&bits[i]==1){
                i=i+1;
            }else if (bits[i]==1&&bits[i+1]==0){
                i=i+1;
            }
        }
        if (i==bits.length-1){
            return true;
        }else{
            return  false;
        }*/
        int c = 0;
        for (int i = bits.length - 2; i >= 0; i--) {
            if(bits[i] == 1){
                ++c;
            }
            else{
                break;
            }
        }
        return c % 2 == 0;
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
        System.out.println(isOneBitCharacter(nums));
    }
}
