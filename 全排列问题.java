package com.xzy;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

/*
有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
 */
public class 全排列问题 {
    private static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("请输入1~N N：");
        int N = in.nextInt();
        int n = 0;
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                for(int k = 1; k <= N; ++k)
                    if(i != j && j != k && i != k && ++n!=0)
                        System.out.println("NO."+n+":"+i+""+j+""+k);
        System.out.println("共有:" + n + "种");
    }
}
