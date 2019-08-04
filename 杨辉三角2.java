package practice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]

来源：力扣（LeetCode）
 */
public class 杨辉三角2 {
    public static List<Integer> getRow(int rowIndex) {
       /* int[][] nums = new int[rowIndex+1][rowIndex+1];
        List<Integer> list2 = new ArrayList<>();
        for (int i = 0; i <rowIndex+1; i++) {
            list2.removeAll(list2);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    nums[i][j] = 1;
                } else {
                    nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];
                }
                list2.add(nums[i][j]);
            }
        }
        return list2;*/

        List<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i <= rowIndex; i++)
        {
            list.add(1);
            for(int j = list.size()-2; j>=1; j--)
            {
                list.set(j, list.get(j-1)+list.get(j));
            }
        }
        return list;

        /*Integer[] result = new Integer[rowIndex+1];
        Arrays.fill(result,0);//填充 用0
        result[0] = 1;
        // 层层递建 杨辉三角
        for(int i = 1; i < result.length;i++){
            for(int j = i ; j > 0; j--){
                result[j] = result[j] + result[j-1];
            }
        }
        return Arrays.asList(result);*/



           /* List<Integer> list = new ArrayList<>(rowIndex+1);
            int cur = 1;
            for(int i=0;i<=rowIndex;i++){
                list.add(cur);
                cur = cur * (rowIndex-i)/(i+1);
            }
            return list;*/
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入要求的行数：");
        int rowIndex = in.nextInt();
        List<Integer> list = getRow(rowIndex);
        for (Integer number:
             list) {
            System.out.print(number+" ");
        }
    }
}
