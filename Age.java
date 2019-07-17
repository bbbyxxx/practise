package com.xzy;

import java.util.Scanner;

/*有n个人坐在一起，问第n个人多少岁？他说比第n-1个人大2岁。
问第n-1个人岁数，他说比第n-2个人大2岁。问第三个人，又说比第n-3人大两岁...
依次类推，问道第1个人，他说是10岁。请问第五个人多大？（要求使用递归）*/
public class Age {
    private static Scanner in = new Scanner(System.in);
    public static int age(int n){
        if(n==1){
            return 10;
        }
        else{
            return age(n-1)+2;
        }
    }

    public static void main(String[] args) {
        System.out.print("请输入要查看第几个人的年龄：");
        int n = in.nextInt();
        System.out.println(age(n));
    }
}
