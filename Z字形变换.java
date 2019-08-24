package practice;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

来源：力扣（LeetCode）
 */
public class Z字形变换 {
    public static  String convert(String s, int numRows) {
        /*if (numRows == 1) return s;
        List<StringBuilder> list = new ArrayList<>();
        for (int i = 0; i < Math.min(numRows,s.length()); i++) {
            list.add(new StringBuilder());
        }
        int step = -1;
        int cnt = 0;
        for (char c:s.toCharArray()
             ) {
            if (cnt==0||cnt==numRows-1){
                step = -step;
            }
            list.get(cnt).append(c);
            cnt += step;
        }
        StringBuilder c = new StringBuilder();
        for (StringBuilder sb:list
             ) {
            c.append(sb);
        }
        return c.toString();*/


        /*
        首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...

对于所有整数 kk，

行 00 中的字符位于索引 k \; (2 \cdot \text{numRows} - 2)k(2⋅numRows−2) 处;
行 \text{numRows}-1numRows−1 中的字符位于索引 k \; (2 \cdot \text{numRows} - 2) + \text{numRows} - 1k(2⋅numRows−2)+numRows−1 处;
内部的 行 ii 中的字符位于索引 k \; (2 \cdot \text{numRows}-2)+ik(2⋅numRows−2)+i 以及 (k+1)(2 \cdot \text{numRows}-2)- i(k+1)(2⋅numRows−2)−i 处;
         */
        if (numRows == 1) return s;

        StringBuilder ret = new StringBuilder();
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret.append(s.charAt(j + i));
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret.append(s.charAt(j + cycleLen - i));
            }
        }
        return ret.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("输入字符串：");
        String s = in.next();
        System.out.println("输入行数：");
        int num = in.nextInt();
        System.out.println(convert(s,num));
    }
}
