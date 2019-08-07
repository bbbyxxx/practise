package com.Fengkuangjava.链式队列;

public class LinkQueue<T> {
    //定义一个内部类Node，Node实例代表链式队列的结点
    private class Node{
        //保存结点数据
        private T data;
        //指向下一个结点的引用
        private Node next;
        //无参数构造器
        public Node(){

        }
        //初始化全部属性的构造器
        public Node(T data,Node next){
            this.data = data;
            this.next = next;
        }
    }
    //保存该链表的头结点
    private Node front;
    //保存该链表的尾结点
    private Node rear;
    //保存该链表已包含的结点数
    private int size;
    //创建空链队列
    public LinkQueue(){
        front = null;
        rear = null;
    }
    //以指定数据元素来创建链式队列，该链式队列只有一个元素
    public LinkQueue(T element){
        front = new Node(element,null);
        rear = front;
        size++;
    }
    //返回链式队列的长度
    public int length(){
        return size;
    }
    //将新元素加入队列
    public void add(T element){
        //如果该链式队列还是空队列
        if (isEmpty()){
            front = new Node(element,null);
            rear = front;
        }else{
            Node newNode = new Node(element,null);
            rear.next = newNode;
            rear = newNode;
        }
        size++;
    }
    //删除队列中front端的元素
    public T remove(){
        Node oldValue = front;
        front = front.next;
        oldValue.next = null;
        size--;
        return oldValue.data;
    }
    //访问链式队列中最后一个元素
    public T element(){
        return front.data;
    }
    //判断链式队列是否为空
    public boolean isEmpty(){
        return size == 0;
    }
    //清空队列
    public void clear(){
        front = null;
        rear = null;
        size = 0;
    }
    //重写toString方法
    public String toString(){
        if (isEmpty()){
            return "[]";
        }else{
            StringBuilder sb = new StringBuilder("[");
            for (Node current = front;current != null;current = current.next){
                sb.append(current.data+",");
            }
            int len = sb.length();;
            return sb.delete(len-1,len).append("]").toString();
        }
    }
}
