package practice;

import java.util.Arrays;
import java.util.Scanner;

public class 两数之和II_输入有序数组 {
    public static Scanner in = new Scanner(System.in);
    public static int[] twoSum(int[] numbers, int target) {
        /*int[] nums=new int[2];
        boolean flag=true;
        for (int i = 0; i < numbers.length-1&&flag; i++) {
            for (int j = i+1; j < numbers.length&&flag; j++) {
                if(numbers[i]+numbers[j]==target){
                    nums[0]=i+1;
                    nums[1]=j+1;
                    flag=false;
                }
                else if(numbers[i]+numbers[j]>target){
                    break;
                }
            }
        }
        return nums;*/
        int i=0;
        int j=numbers.length-1;
        while(i!=j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            }
              else {
                break;
            }
        }
        return new int[]{i + 1, j + 1};
    }

    public static void main(String[] args) {
        int n,target;
        System.out.print("请输入输入长度：");
        n = in.nextInt();
        System.out.print("请输入数组元素：");
        int[] nums = new int[n];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        System.out.print("请输入目标值：");
        target = in.nextInt();
        System.out.println(Arrays.toString(twoSum(nums,target)));//输出找到的下标
    }
}
