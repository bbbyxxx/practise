package com.Fengkuangjava;

import java.util.*;
//基数排序：是桶排序的特殊情况，基本思想为：将所有元素分为若干组
//分组依据为其位数，比如：个位、十位、百位...然后将分号组的元素按顺序拿出来放入数组中，
//重复此过程，直到所有位数都分配过（即数组中最大数的位数也已经用过）
//基数排序对有负数和0的数列难以进行排序
//
//因此，往往有0和负数的数组一般我们都不用基数来进行排序
//基数排序的要点就两个：
//
//分配：按照元素的大小来放入不同的桶子里
//回收：将桶子里的元素按桶子顺序重新放到数组中
//重复.....两个步骤
public class 基数排序 {
        public static void main(String[] args) {
            int max = Integer.MIN_VALUE;
            Scanner in = new Scanner(System.in);
            System.out.print("请输入数组长度：");
            int n = in.nextInt();
            System.out.print("请输入数组元素：");
            int[] nums = new int[n];
            for(int i=0;i<n;i++) {
                nums[i] = in.nextInt();
            }
            for (int i = 0; i < n; i++) {
                if (nums[i]>max){
                    max = nums[i];
                }
            }
            int cnt = 0;
            while(max!=0){
                cnt++;
                max /=10;
            }
            radixSort(nums,cnt);
            System.out.println(Arrays.toString(nums));
        }

        public static void radixSort(int[] n,int num) {
            ArrayList<Integer>[] list = new ArrayList[10];//定义桶空间
            for(int i=0;i<list.length;i++) {//创建桶
                list[i] = new ArrayList<Integer>();
            }
            for(int pos=0;pos<num;pos++) {//遍历每一位数，以位数为依据排序（即入桶，还原）
                for(int i=0;i<list.length;i++) {//每一次清空桶
                    list[i].clear();
                }
                for(int i=0;i<n.length;i++) {//向相应桶中添加元素
                    int key = key(n[i],pos);//获取桶位置
                    list[key].add(n[i]);//添加元素到相应的桶中
                }
                int index = 0;
                for(int i=0;i<list.length;i++) {//将各个桶中的元素按遍历顺序还原回数组中
                    if(list[i]!=null) {
                        for(int j=0;j<list[i].size();j++) {
                            n[index++] = list[i].get(j);
                        }
                    }
                }
            }
        }

        public static int key(int n,int pos) {
            /*int result = 1;
            for(int i=0;i<pos;i++) {
                result *= 10;
            }
            return (n/result)%10;*/
            while(pos-- != 0){//位数跑完 定位到对应的位数
                n /= 10;
            }
            return n%10;//求出相应的位数
        }
}
