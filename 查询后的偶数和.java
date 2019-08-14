package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给出一个整数数组 A 和一个查询数组 queries。

对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val 加到 A[index] 上。
然后，第 i 次查询的答案是 A 中偶数值的和。

（此处给定的 index = queries[i][1] 是从 0 开始的索引，每次查询都会永久修改数组 A。）

返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i 次查询的答案。

 

示例：

输入：A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
输出：[8,6,2,4]
解释：
开始时，数组为 [1,2,3,4]。
将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length

来源：力扣（LeetCode）
 */
public class 查询后的偶数和 {
    public static int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        /*超时int cnt = 0;
        int k = 0;
        int[] nums = new int[A.length];
        for (int i = 0; i < queries.length; i++) {
            A[queries[i][1]] = A[queries[i][1]] + queries[i][0];
            for (int j = 0; j < A.length; j++) {
                if (A[j]%2==0){
                    cnt += A[j];
                }
            }
            nums[k++] = cnt;
            cnt = 0;
        }
        return nums;*/

        /*int cnt = 0;
        int k = 0;
        int t = 0;
        int[] nums = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            if (A[i]%2==0){
                cnt += A[i];
            }
        }
        for (int i = 0; i < queries.length; i++) {
            t = A[queries[i][1]];
            A[queries[i][1]] = A[queries[i][1]] + queries[i][0];
            if ((t%2==1||t%2==-1)&&A[queries[i][1]]%2==0){
                cnt += A[queries[i][1]];
            }else if (A[queries[i][1]]%2==0&&t%2 == 0) {
                cnt += A[queries[i][1]] - t;
            }else if (t%2==0&&(A[queries[i][1]]%2==1||A[queries[i][1]]%2==-1)){
                cnt -= t;
            }
            nums[k++] = cnt;
        }
        return nums;*/

        int length = A.length;
        int[] result = new int[length];
        int res = 0;
        for(int i = 0; i < length; i ++)
        {
            if(A[i] % 2 == 0)
            {
                res += A[i];
            }
        }
        for(int i = 0; i < queries.length; i ++)
        {
            int before = A[queries[i][1]];
            A[queries[i][1]] += queries[i][0];

            if(before % 2 == 0)
            {
                res -= before;
            }
            if(A[queries[i][1]] % 2 == 0)
            {
                res += A[queries[i][1]];
            }
            result[i] = res;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] nums = new int[]{1,2,3,4};
        System.out.println(Arrays.toString(nums));
        int[][] queries = new int[][]{{1,0},{-3,1},{-4,0},{2,3}};
        System.out.println(Arrays.toString(sumEvenAfterQueries(nums,queries)));
    }
}
