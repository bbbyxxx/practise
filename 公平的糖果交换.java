package practice;

import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。

因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
方法：方程求解

思路

如果爱丽丝交换糖果 x，她将会期待交换具有特定量的糖果 y 回来。

算法

设爱丽丝和鲍勃分别总计有 S_A, S_BS
A
​
 ,S
B
​
  的糖果。

如果爱丽丝给了糖果 xx，并且收到了糖果 yy，那么鲍勃收到糖果 xx 并给出糖果 yy。那么，我们一定有

S_A - x + y = S_B - y + x
S
A
​
 −x+y=S
B
​
 −y+x

对于公平的糖果交换。这意味着

y = x + \frac{S_B - S_A}{2}
y=x+
2
S
B
​
 −S
A
​

​


我们的策略很简单。对于爱丽丝拥有的每个糖果 xx，如果鲍勃有糖果 y = x + \frac{S_B - S_A}{2}y=x+
2
S
B
​
 −S
A
​

​
 ，我们就返回 [x，y][x，y]。我们在常量时间内使用集 Set 结构来检查Bob是否拥有所需的糖果 yy。

 */
public class 公平的糖果交换 {
    public static int[] fairCandySwap(int[] A, int[] B) {
        /*超时int[] nums = new int[2];
        int temp;
        int sum1 = 0,sum2 = 0;
        boolean flag = true;
        for (int i = 0; i < A.length&&flag; i++) {
            for (int j = 0; j < B.length&&flag; j++) {//交换
                temp = A[i];
                A[i] = B[j];
                B[j] = temp;
                for (int k = 0; k < A.length; k++) {
                    sum1 += A[k];
                }
                for (int q = 0; q < B.length; q++) {
                    sum2 += B[q];
                }
                if (sum1 == sum2){
                    nums[] = A[i];
                    nums[0] = B[j];
                    flag = false;
                }else{//交换回来
                    temp = A[i];
                    A[i] = B[j];
                    B[j] = temp;
                }
                sum1 = 0;
                sum2 = 0;
            }
        }
        return nums;*/

        /*int[] ans = new int[2];
        int sumA = 0, sumB = 0;
        for(int i: A){
            sumA += i;
        }
        for(int j: B){
            sumB += j;
        }
        Arrays.sort(A);
        Arrays.sort(B);
        int temp = sumA-(sumA+sumB)/2;
        int i = 0, j = 0;
        while(i<A.length&&j<B.length){
            if(A[i]-B[j]==temp){
                ans[0] = A[i];
                ans[1] = B[j];
                break;
            }
            else if(A[i]-B[j]>temp){
                j++;
            }
            else if(A[i]-B[j]<temp){
                i++;
            }
        }
        return ans;*/

        int sumA = 0, sumB = 0;

        for (int i : A)//A数组和
            sumA += i;
        for (int i : B)//B数组和
            sumB += i;

        Set<Integer> setB = new HashSet<>();//存放B数组所有数字
        for (int i : B)
            setB.add(i);

        int del = (sumA - sumB) / 2;//计算需要交换糖果差值的一半
        for (int i : A) {
            if (setB.contains(i - del)) {//在B中查找
                return new int[] { i, i-del };
            }
        }

        throw null;
    }

    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.print("请输入数组A长度：");
        int n = in.nextInt();
        System.out.print("请输入数组B长度：");
        int m = in.nextInt();
        System.out.print("请输入数组A元素：");
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextInt();
        }
        System.out.print("请输入数组B元素：");
        int[] B =new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = in.nextInt();
        }
        int[] out = fairCandySwap(A,B);
        for (int i = 0; i < out.length; i++) {
            System.out.println(out[i]);
        }
    }
}
