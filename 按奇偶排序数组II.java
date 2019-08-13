package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

来源：力扣（LeetCode）
 */
public class 按奇偶排序数组II {
    public  static int[] sortArrayByParityII(int[] A) {
        /*int i = 0;
        while(i<A.length){
            if ((A[i]%2==0&&i%2==0)||(A[i]%2==1&&i%2==1)){
                i++;
            }else{
                if (i%2==0) {
                    for (int k = i; k < A.length; k++) {
                        if (A[k]%2==0&&k%2==1){
                            int temp = A[i];
                            A[i] = A[k];
                            A[k] = temp;
                            break;
                        }
                    }
                }else if (i%2==1){
                    for (int k = i; k < A.length; k++) {
                        if (A[k]%2==1&&k%2==0){
                            int temp = A[i];
                            A[i] = A[k];
                            A[k] = temp;
                            break;
                        }
                    }
                }
                i++;
            }
        }
        return A;*/

        int j = 1;

        for(int i = 0 ; i < A.length ;i+=2){
            if(A[i] % 2 == 1){
                while(A[j] % 2 == 1) {
                    j += 2;
                }
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;

            }
        }
        return A;
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
        System.out.println(Arrays.toString(sortArrayByParityII(nums)));
    }
}
