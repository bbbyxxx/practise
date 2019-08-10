package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。

水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。

反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

示例 1:

输入: [[1,1,0],[1,0,1],[0,0,0]]
输出: [[1,0,0],[0,1,0],[1,1,1]]
解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
示例 2:

输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
说明:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

来源：力扣（LeetCode）
 */
public class 翻转图像 {
    public static int[][] flipAndInvertImage(int[][] A) {
       /* for (int i = 0; i < A.length; i++) {
            for (int j = 0,k=A[i].length-1; j <k ; j++,k--) {
                int temp = A[i][j];
                A[i][j] = A[i][k];
                A[i][k] = temp;
            }
        }
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j <A[i].length ; j++) {
                if (A[i][j]==0){
                    A[i][j]=1;
                }else{
                    A[i][j]=0;
                }
            }
        }
        return A;*/

        if (A == null) {
            return A;
        }
        if (A.length == 0 || A[0].length == 0){
            return A;
        }
        for (int i = 0; i < A.length; i++) {
            for (int j = 0, k = A[0].length - 1; j < (A[0].length + 1) / 2; j++, k--) {
                int temp = A[i][j] ^ 1;
                A[i][j] = A[i][k] ^ 1;
                A[i][k] = temp;
            }
        }
        return A;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入行数：");
        int row = in.nextInt();
        System.out.print("请输入列数：");
        int col = in.nextInt();
        System.out.println("请输入二维数组元素：");
        int[][] nums = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                nums[i][j] = in.nextInt();
            }
        }
        flipAndInvertImage(nums);
        for (int i = 0; i < row; i++) {
                System.out.println(Arrays.toString(nums[i]));
        }
    }
}
