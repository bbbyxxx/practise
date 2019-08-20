package practice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

来源：力扣（LeetCode）
 */
public class 数组的相对排序 {
    public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        /*List<Integer> list = new ArrayList<>();
        for (int i = 0; i < arr2.length; i++) {
            for (int j = 0; j < arr1.length; j++) {
                if (arr2[i] == arr1[j]){
                    list.add(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }
        int[] su = new int[arr1.length - list.size()];
        int n = 0;
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i]!=-1){
                su[n++] = arr1[i];
            }
        }
        Arrays.sort(su);
        for (int i = 0; i < su.length; i++) {
            list.add(su[i]);
        }
        int[] nums = new int[list.size()];
        int m = 0;
        for (Integer key:
             list) {
            nums[m++] = key;
        }
        return nums;*/

        int[] cnt = new int[1001];
        for (int n: arr1) cnt[n]++;
        int[] res = new int[arr1.length];
        int i = 0;
        for (int n: arr2) {
            for (int j = 0; j < cnt[n]; j++) {
                res[i++] = n;
            }
            cnt[n] = 0;
        }
        for (int j = 0; j <= 1000; j++) {
            for (int k = 0; k < cnt[j]; k++) {
                res[i++] = j;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组n1和n2的长度：");
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums1 = new int[n1];
        int[] nums2 = new int[n2];
        for (int i = 0; i < n1; i++) {
            nums1[i] = in.nextInt();
        }
        for (int j = 0; j < n2; j++) {
            nums2[j] = in.nextInt();
        }
        System.out.println(Arrays.toString(relativeSortArray(nums1,nums2)));
    }
}
