package com.Fengkuangjava.栈;

import java.util.Arrays;

public class SequenceStack<T> {
    private int DEFAULT_SIZE = 10;
    //保存数组长度
    private int capacity;
    //定义当底层数组容量不够时，程序每次增加的数组长度
    private int capacityIncrement = 0;
    //定义一个数组用于保存顺序栈的元素
    private Object[] elementdata;
    //保存顺序栈中元素的当前个数
    private int size = 0;
    //以默认数组长度创建空顺序栈
    public SequenceStack(){
        capacity = DEFAULT_SIZE;
        elementdata = new Object[capacity];
    }
    //以一个初始化元素来创建顺序栈
    public SequenceStack(T element){
        this();
        elementdata[0] = element;
        size++;
    }
    /**
     * 以指定长度的数组来创建顺序栈
     * @param  element 指定顺序栈中第一个元素
     * @param initSize 指定顺序栈底层数组的长度
     */
    public SequenceStack(T element,int initSize){
        this.capacity = initSize;
        elementdata = new Object[capacity];
        elementdata[0] = element;
        size++;
    }
    /**
     * 以指定长度的数组来创建顺序栈
     * @param  element 指定顺序栈中第一个元素
     * @param initSize 指定顺序栈底层数组的长度
     * @param capacityIncrement 指定顺序栈底层数组的长度不够时，底层数组每次增加的长度
     */
    public SequenceStack(T element,int initSize,int capacityIncrement){
        this.capacity = initSize;
        this.capacityIncrement = capacityIncrement;
        elementdata = new Object[capacity];
        elementdata[0] = element;
        size++;
    }
    //获取顺序栈的大小
    public int length(){
        return size;
    }
    //入栈
    public void push(T element){
        ensureCapacity(size+1);
        elementdata[size++] = element;
    }
    //判断是否扩展底层数组
    private void ensureCapacity(int minCapacity){
        //如果数组的原有长度小于目前所需的长度
        if (minCapacity>capacity){
            if (capacityIncrement>0){
                while(capacity<minCapacity){
                    //不断地将capacity长度加capacityIncrement
                    //直到capacity大于minCapacity为止
                    capacity += capacityIncrement;
                }
            }else{
                //不断地将capacity*2，直到capacity大于minCapacity为止
                while(capacity<minCapacity){
                    capacity<<=1;
                }
            }
            elementdata = Arrays.copyOf(elementdata,capacity);
        }
    }
    //出栈
    public T pop(){
        T oldValue = (T)elementdata[size-1];
        //释放栈顶元素
        elementdata[--size] = null;
        return oldValue;
    }
    //返回栈顶元素
    public T peek(){
        return (T)elementdata[size-1];
    }
    //判断是否为空栈
    public boolean isEmpty(){
        return size == 0;
    }
    //清空顺序栈
    public void clear(){
        //将底层数组所有元素赋为null
        Arrays.fill(elementdata,null);
        size = 0;
    }
    //重写toString方法
    public String toString(){
        if(size==0){
            return "[]";
        }else{
            StringBuilder sb = new StringBuilder("[");
            for (int i = size-1; i > -1; i--) {
                sb.append(elementdata[i]+",");
            }
            int len = sb.length();
            return sb.delete(len-1,len).append("]").toString();
        }
    }
}
