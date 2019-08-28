package com.Fengkuangjava;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/*
桶排序的原理是：将数组分到有限数量的桶子里。
每个桶子再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。
桶排序是鸽巢排序的一种归纳结果。
当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间（Θ（n））。
但桶排序并不是 比较排序，他不受到 O(n log n) 下限的影响。主要原理是：利用了空间换时间的方法。
所以，桶排序的复杂度依赖于两部分：
(1) 循环计算每个关键字的桶映射函数，这个时间复杂度是O(N)。
(2) 利用先进的比较排序算法对每个桶内的所有数据进行排序，其时间复杂度为 ∑ O(Ni*logNi) 。其中Ni 为第i个桶的数据量。

总结： 桶排序的平均时间复杂度为线性的O(N+C)，其中C=N*(logN-logM)。
如果相对于同样的N，桶数量M越大，其效率越高，最好的时间复杂度达到O(N)。
当然桶排序的空间复杂度 为O(N+M)，如果输入数据非常庞大，而桶的数量也非常多，则空间代价无疑是昂贵的。
此外，桶排序是稳定的。
 */
public class 桶排序 {//BucketSort
    //桶排序：将N个数，分成m个桶，桶之间的元素递增，然后对桶内的元素进行排序，最后输出所有元素
    int bucketSize = 10;
    int arraySize = 100;

    public static void main(String[] args){
        桶排序 bs = new 桶排序();
        int[] array = bs.getArray();
        bs.bucketSort(array);
    }

    public int[] getArray(){
        int[] arr = new int[arraySize];
        Random r = new Random();
        for (int i = 0; i < arraySize; i++) {
            arr[i] = r.nextInt(10000);
        }
        return arr;
    }

    public void bucketSort(int[] a){
        List<Integer>[] bucket = new ArrayList[bucketSize];
        for (int i = 0; i < a.length; i++) {
            int temp = a[i] / 1000;//分组区间大小：1000  得到对应桶下标
            if (bucket[temp] == null){
                bucket[temp] = new ArrayList<Integer>();
            }
            bucket[temp].add(a[i]);
        }
        //对各个桶内的list中的元素进行排序
        for (int j = 0; j < bucketSize; j++) {
            insertSort(bucket[j]);//对桶内的元素进行排序
            printList(bucket[j]);//输出桶中的元素
        }
    }

    public void printList(List<Integer> list){
        while(list.size() > 0){
            System.out.print(list.remove(0)+"\t");
        }
    }

    public void insertSort(List<Integer> list){//对每个list进行排序
        Collections.sort(list);
    }
}
