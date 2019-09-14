package KMP;

import java.util.Arrays;
import java.util.Scanner;

public class KMP {
    public static int[] prefix(String pattern){//获得模式串前后缀匹配字符串的长度
        //并存入数组中
        int len = pattern.length();//获取模式串的长度
        int[] result = new int[len];//创建和模式串等长的存取匹配长度的数组
        result[0] = 0;//result的第一个元素无匹配的值，所以其匹配长度肯定为0
        int p = 0;//标志模式串匹配的长度
        int i = 1;//从1开始遍历剩下的字符并判断
        while (i<len){
            if (pattern.charAt(i) == pattern.charAt(p)){//相等的情况
                p++;//匹配长度+1
                result[i] = p;//赋给数组对应位置
                i++;//继续向后判断
            }else{//不相等的情况
                if (p>0) {//没到第一个位置，预防越界
                    p = result[p - 1];//p等于匹配长度数组的前一个位置，即侧着移位
                }else{//不相等且到了第一个位置
                    result[i] = p;//赋0
                    i++;//继续向后判断
                }
            }
        }
        return result;
    }

    public static void change(int[] nums){
        for (int i = nums.length-1; i >0; i--) {//将所有匹配长度前移，形成统一
            nums[i] = nums[i-1];
        }
        //给nums[0]赋值
        nums[0] = -1;
    }

    public static void kmpSearch(String nums,String pattern){
        int[] array1 = prefix(pattern);//array1为统计前后缀匹配长度的数组
        change(array1);
        int i = 0;
        int j = 0;
        while(i<nums.length()){
            if (j==pattern.length()-1&&nums.charAt(i)==pattern.charAt(j)){//说明匹配完了，成功
                System.out.println("在主串中下标为："+(i-pattern.length()+1)+"的位置定位到了模式串");
                //匹配完成后，继续向后匹配
                j = array1[j];
            }
            if (nums.charAt(i)==pattern.charAt(j)){//相等同时挪动
                i++;
                j++;
            }else{//不相等
                j = array1[j];//将j移到其对应的已匹配的地方，从此位置继续匹配
                if (j == -1){//说明没有匹配的，将主串和模式串的指针都移动
                    i++;
                    j++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入主串：");
        String nums = in.next();
        System.out.print("请输入模式串:");
        String pattern = in.next();
        kmpSearch(nums,pattern);
    }
}
