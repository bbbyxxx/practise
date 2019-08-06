package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。

给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

示例 1:

输入:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
输出:
[[1,2,3,4]]
解释:
行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
示例 2:

输入:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
输出:
[[1,2],
 [3,4]]
解释:
没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
注意：

给定矩阵的宽和高范围在 [1, 100]。
给定的 r 和 c 都是正数。

来源：力扣（LeetCode）
 */
public class 重塑矩阵 {
    public static int[][] matrixReshape(int[][] nums, int r, int c) {
        /*int[][] newNums = new int[r][c];//创建一个新二维数组
        int t,n=0,m=0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[i].length; j++) {
                t=nums[i][j];
                if(m!=r){
                    newNums[m][n] = t;
                }
                if(n<c&&m<r){
                    n++;
                }
                if(n==c&&m!=r){
                    n=0;
                    m++;
                }
            }
        }
        if (nums.length*nums[0].length!=r*c){//说明不合法
            return nums;
        }else{
            return newNums;
        }*/
        int row = nums.length;
        int column = nums[0].length;
        if (row * column != r * c) {
            // 输入的行列不符合原始数组的行列  则返回原始数组
            return nums;
        }
        int x = 0;
        int y = 0;
        int[][] reshape = new int[r][c];
        for (int[] num : nums) { // 从二维数组中遍历出一维数组
            for (int i : num) {  // 从一维数组中遍历出值
                reshape[x][y] = i; // 将值赋到新的数组
                if (++y == c) {
                    y = 0;
                    x++;
                }
            }
        }
        return reshape;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] nums={{1,2},{3,4}};
        int r,c;
        System.out.print("请输入要重塑的行数和列数：");
        r = in.nextInt();
        c = in.nextInt();
        nums = matrixReshape(nums,r,c);
        for (int i = 0; i < nums.length; i++) {
            System.out.println(Arrays.toString(nums[i]));
        }
    }
}
