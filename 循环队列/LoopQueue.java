package com.Fengkuangjava.循环队列;

import java.util.Arrays;

public class LoopQueue<T>{
    private int DEFAULT_SIZE = 10;
    //保存数组的长度
    private int capacity;
    //定义一个数组保存循环队列的元素
    private Object[] elementData;
    //保存循环队列中元素的当前个数
    private int front = 0;
    private int rear = 0;
    //以默认数组长度创建空循环队列
    public LoopQueue(){
        capacity = DEFAULT_SIZE;
        elementData = new Object[capacity];
    }
    //以一个初始化元素创建循环队列
    public LoopQueue(T element){
        this();
        elementData[0] = element;
        rear++;
    }
    /**
     * 以指定长度的数组来创建循环队列
     * @param element 指定循环队列中第一个元素
     * @param initSize 指定循环队列底层数组的长度
     */
    public LoopQueue(T element,int initSize){
        this.capacity = initSize;
        elementData = new Object[capacity];
        elementData[0] = element;
        rear++;
    }
    //获取循环队列的大小
    public int length(){
        if (isEmpty()){
            return 0;
        }
        return rear>front?rear-front:capacity-(front-rear);
    }
    //插入队列
    public void add(T element){
        if (rear == front&&elementData[front]!=null){
            throw new IndexOutOfBoundsException("队列已满的异常");
        }
        elementData[rear++] = element;
        //如果rear已到头，那就转头
        rear = rear ==capacity?0:rear;
    }
    //移除队列
    public T remove(){
        if (isEmpty()){
            throw new IndexOutOfBoundsException("空队列异常");
        }
        //保留队列front端的元素的值
        T oldValue = (T)elementData[front];
        //释放队列front端的元素
        elementData[front++] = null;
        //如果front已经到头，那就转头
        front = front == capacity ? 0 : front;
        return oldValue;
    }
    //返回队列首端元素，但不删除
    public T element(){
        if (isEmpty()){
            throw new IndexOutOfBoundsException("空队列异常");
        }
        return (T)elementData[front];
    }
    //判断循环队列是否为空队列
    public boolean isEmpty(){
        //rear == front 且 rear处的元素为null
        return rear == front && elementData[rear] == null;
    }
    //清空循环队列
    public void clear(){
        //将底层数组所有元素赋为null
        Arrays.fill(elementData,null);
        front = 0;
        rear = 0;
    }
    //重写toString方法
    public String toString(){
        if (isEmpty()){
            return "[]";
        }else{
            //如果front<rear，有效元素就是front-rear之间
            if (front<rear){
                StringBuilder sb = new StringBuilder("[");
                for (int i = front; i < rear; i++) {
                    sb.append(elementData[i]+",");
                }
                int len = sb.length();
                return sb.delete(len-1,len).append("]").toString();
            }else{
                //有效元素为front到capacity，0到rear
                StringBuilder sb = new StringBuilder("[");
                for (int i = front; i < capacity; i++) {
                    sb.append(elementData[i]+",");
                }
                for (int j = 0; j < rear; j++) {
                    sb.append(elementData[j]+",");
                }
                int len = sb.length();
                return sb.delete(len-1,len).append("]").toString();
            }
        }
    }
}
