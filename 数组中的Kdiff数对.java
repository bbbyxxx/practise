package practice;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import static java.util.Arrays.sort;

/*
给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和 j 都是数组中的数字，且两数之差的绝对值是 k.

示例 1:

输入: [3, 1, 4, 1, 5], k = 2
输出: 2
解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个1，但我们只应返回不同的数对的数量。
示例 2:

输入:[1, 2, 3, 4, 5], k = 1
输出: 4
解释: 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
示例 3:

输入: [1, 3, 1, 5, 4], k = 0
输出: 1
解释: 数组中只有一个 0-diff 数对，(1, 1)。
注意:

数对 (i, j) 和数对 (j, i) 被算作同一数对。
数组的长度不超过10,000。
所有输入的整数的范围在 [-1e7, 1e7]。

来源：力扣（LeetCode）
 */
public class 数组中的Kdiff数对 {
    public static int findPairs(int[] nums, int k) {
        /*int cnt = 0,t=0;
        Arrays.sort(nums);
        if(k==0){
            for (int i = 0; i < nums.length-1; i++) {
                    if(nums[i]==nums[i+1]&&nums[i]!=t) {
                        t = nums[i];
                        cnt++;
                    }
            }
        }else{
            for (int i = 0; i < nums.length-1; i++) {
                for (int j = i+1; j < nums.length; j++) {
                    if(nums[j]==nums[i]){
                        break;
                    }
                    if(nums[j]-nums[i]==k&&nums[j]!=t) {
                        t=nums[j];
                        cnt++;
                    }
                }
            }
        }
        return cnt;*/
        if (k < 0) {
            return 0;
        }
        //向HashSet集合中添加元素时，首先判断是否存在（contains），依据为hashCode和equals，如果不存在添加，否则忽略（不是覆盖）
        Set<Integer> exists = new HashSet<>();
        Set<Integer> pair = new HashSet<>();
        for (int n : nums) {
            if (exists.contains(n - k)) {
                pair.add(n - k);
            }
            if (exists.contains(n + k)) {
                pair.add(n);
            }
            exists.add(n);
        }
        return pair.size();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,k;
        System.out.println("请输入数组长度：");
        n = in.nextInt();
        int[] nums = new int[n];
        System.out.println("请输入数组元素：");
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        System.out.println("请输出k：");
        k = in.nextInt();
        //输出结果
        System.out.println(findPairs(nums,k));
    }
}
