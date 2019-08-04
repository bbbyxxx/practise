package practice;
/*
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class 杨辉三角 {
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        int[][] nums= new int[numRows][numRows];
        for (int i = 0; i < numRows; i++) {
            List<Integer> next = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
             if(j==0||j==i){
                 nums[i][j] = 1;
             }else{
                    nums[i][j] = nums[i - 1][j-1] + nums[i - 1][j];
                }
             next.add(nums[i][j]);
            }
            list.add(next);
        }
        return list;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入要输出的行数：");
        int numRows = in.nextInt();
        List<List<Integer>> out = generate(numRows);
        for (List<Integer> number: out) {
            System.out.println(number);
        }
    }
}
