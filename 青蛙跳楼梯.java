package com.xzy;

import java.util.Scanner;
/*问题一：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
/*public class 青蛙跳楼梯 {
    private static Scanner in = new Scanner(System.in);
    public static int jump(int n){
        if(n==1){
            return 1;
        }
        else if (n==2){
            return 2;
        }
        else{
            return jump(n-1)+jump(n-2);
        }

    }
    public static void main(String[] args) {
        System.out.print("请输入楼梯数：");
        int n = in.nextInt();
        System.out.println(jump(n));
    }
}*/



/*
问题二：一只青蛙一次可以跳上1级台阶，
也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
public class 青蛙跳楼梯 {
    private static Scanner in = new Scanner(System.in);
    public static int jump(int n){
        if(n==1){
            return 1;
        }
        return 2*jump(n-1);
    }
    public static void main(String[] args) {
        System.out.print("请输入楼梯数：");
        int n = in.nextInt();
        System.out.println(jump(n));
    }
}
