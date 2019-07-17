package com.xzy;

import java.util.Scanner;

/*
有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13…求出这个数列的前20项之和。
 */
public class 分子分母均为斐波那契数求和 {
    private static Scanner in = new Scanner(System.in);
    public static double sum(int N){
        double cnt = 0;
        double a=2,b=1,t=0;
        for (int i = 0; i < N; i++) {
            cnt+=a/b;
            t=a;
            a=a+b;
            b=t;
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.print("请输入要查找前N项的和：");
        int N = in.nextInt();
        System.out.print("求出的和为："+sum(N));
    }

}
