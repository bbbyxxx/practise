package practice;

import java.util.Scanner;

/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例 1:

输入: [1,12,-5,-6,50,3], k = 4
输出: 12.75
解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

注意:

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

来源：力扣（LeetCode）
 */
public class 子数组最大平均数1 {
    public static double findMaxAverage(int[] nums, int k) {
        //超时
        /*Double max = Double.MIN_VALUE;
        Double sum = 0.0;
        for (int i = 0; i <nums.length-k+1; i++) {
            sum = 0.0;
            for (int j = i; j <k+i; j++) {
                sum += nums[j];
            }
            if(sum>max){
                max = sum;
            }
        }
        if (k==1&&nums.length==1){
            max =(double)nums[0];
        }
        return max/k;*/

        //类似于滑动窗口
        /*double max1 = Integer.MIN_VALUE;
        double sum = 0.0;
        int i;
        for (i = 0; i < k; i++) {//获取第一个窗口的和值
            sum += nums[i];
        }
        max1 = Math.max(max1,sum);
        while(i<nums.length){
            //加上右端的 减去 左端的
            sum += nums[i] - nums[i-k];
            max1 = Math.max(max1,sum);
            i++;
        }
        return max1/k;*/


        int sum = 0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }

        //记录第一个i  和  i+k   sum+nums[i+k-1]-nums[i-1];
        int temp=sum;
        for(int i=1;i+k-1<nums.length;++i){
            temp = temp+nums[i+k-1]-nums[i-1];
            if(temp>sum) sum = temp;
        }

        return sum/(double)k;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度：");
        int n = in.nextInt();
        System.out.print("请输入数组元素:");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        System.out.print("请输入k值：");
        int k = in.nextInt();
        System.out.println(findMaxAverage(nums,k));
    }
}
