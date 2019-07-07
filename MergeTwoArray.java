package practice;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class MergeTwoArray {
    public static Scanner in = new Scanner(System.in);
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-n,j=0;
        while(i<m){
            nums1[i++]=nums2[j++];
        }
        Arrays.sort(nums1);
        for (int l = 0; l < m; l++) {
            System.out.print(nums1[l]+"  ");
        }
    }

    public static void main(String[] args) {
        int n1,n2;
        System.out.print("请分别输入两个数组的长度：");
        n1=in.nextInt();
        n2=in.nextInt();
        int[] nums1 = new int[n1+n2];
        int[] nums2 = new int[n2];
        System.out.print("请输入数组nums1的元素值：");
        for (int i = 0; i < n1; i++) {
            nums1[i]=in.nextInt();
        }
        for (int m = n1; m <n1+n2; m++) {
            nums1[m]=0;
        }
        System.out.print("请输入数组nums2的元素值：");
        for (int j = 0; j < nums2.length; j++) {
            nums2[j] = in.nextInt();
        }
        //System.out.println(Arrays.toString(nums1));
        //System.out.println(Arrays.toString((nums2)));
        merge(nums1,n1+n2,nums2,n2);
    }
}



/*
int p1=m-1;
        int p2=n-1;
        int p3=m+n-1;
        while(p1>=0&&p2>=0){
           if(nums1[p1]>=nums2[p2]){
                nums1[p3--]=nums1[p1--];
            }else{
                nums1[p3--]=nums2[p2--];
            }
        }
        while(p1<0&&p2>=0){
            nums1[p3--]=nums2[p2--];
        }
        while(p1>=0&&p2<0){
            nums1[p3--]=nums1[p1--];
        }
 */