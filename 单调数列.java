package practice;

import java.util.Scanner;

/*
如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。

 

示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false
示例 4：

输入：[1,2,4,5]
输出：true
示例 5：

输入：[1,1,1]
输出：true
 

提示：

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

来源：力扣（LeetCode）
 */
public class 单调数列 {
    public static boolean isMonotonic(int[] A) {
        /*int cnt = 0;
        int flag = 0;
        int k =-1;
        for (int i = 1; i < A.length; i++) {
            if (A[i]<A[i-1]){
                flag = 1;
                break;
            }else if (A[i]==A[i-1]){
                cnt++;
            }
        }
        if (cnt == A.length-1){//所有元素相等
            return true;
        }
        else if (flag == 1){//降序
            for (int i = 1; i < A.length; i++) {
                if (A[i]>A[i-1]){
                    k=0;
                    break;
                }
            }
        }else if(flag == 0){//升序
            for (int i = 1; i < A.length; i++) {
                if (A[i] < A[i - 1]) {
                    k = 0;
                    break;
                }
            }
        }
        if (k!=0){
            return true;
        }else{
            return false;
        }*/

        //        1.boolean判断

//        boolean l = true, g = true;
//        for (int i = 0; i < A.length - 1; i++) {
//            if (A[i] > A[i + 1]) {
//                l = false;
//                break;
//            }
//        }
//        for (int i = 0; i < A.length - 1; i++) {
//            if (A[i] < A[i + 1]) {
//                g = false;
//                break;
//            }
//        }
//        return l || g;

//        2.length判断

        int l = 1, g = 1;
        for (; l < A.length && A[l - 1] <= A[l]; l++)
            ;
        if (l == A.length) {
            return true;
        }
        for (; g < A.length && A[g - 1] >= A[g]; g++)
            ;
        if (g == A.length) {
            return true;
        }
        return false;
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
        System.out.println(isMonotonic(nums));
    }
}
