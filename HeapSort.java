package 堆排序;

import java.util.Arrays;

//从0排的:
/*
    parent = (i-1)/2;
    c1 = 2i+1;
    c2 = 2i+2;
 */
public class HeapSort {
    public static void heapSort(int[] nums,int n){
        buildHeap(nums,n);
        for (int i = nums.length-1; i >= 0 ;i--) {
            swap(nums,i,0);
            heapify(nums,i,0);
        }
    }

    public static void heapify(int[] tree,int n,int i){//i表示第几个节点,调整堆
        int c1 = 2*i+1;
        int c2 = 2*i+2;
            int max = i;
            if (c1<n&&tree[max]<tree[c1]){
                max = c1;
            }
            if (c2<n&&tree[max]<tree[c2]){
                max = c2;
            }
            if (max!=i){//说明需要交换
                swap(tree,max,i);
                heapify(tree,n,max);
            }
    }

    public static void swap(int[] tree,int max,int i){
        int t;
        t = tree[max];
        tree[max] = tree[i];
        tree[i] = t;
    }

    public static void buildHeap(int[] tree,int n){//建堆
        int lastNode = n-1;//最后一个节点
        int parent = (lastNode-1)/2;//父节点
        for (int j = n-1; j >= 0; j--) {
            heapify(tree,n,j);//调整堆，交换结点
        }
    }

    public static void main(String[] args) {
        int[] nums = {3,0,0,-1,3,2,5,-9,8,4,0,0};
        heapSort(nums,nums.length);
        System.out.println(Arrays.toString(nums));
    }
}
