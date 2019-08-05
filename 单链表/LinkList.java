package com.Fengkuangjava.单链表;

public class LinkList<T> {
    //定义一个内部类Node，Node实例代表链表的结点
    private class Node{
        //保存结点的数据
        private T data;
        //指向下一个结点的引用
        private Node next;
        //无参构造器
        public Node(){

        }
        //初始化全部属性的构造器
        public Node(T data,Node next){
            this.data = data;
            this.next = next;
        }
    }
    //保存该链表的头结点
    private Node header;
    //保存该链表的尾结点
    private Node tail;
    //保存该链表中已包含的结点数
    private int size;
    //创建空链表
    public LinkList(){
        //空链表，header和tail都是null
        header = null;
        tail = null;
    }
    //以指定元素来创建链表，该链表只有一个元素
    public LinkList(T element){
        header = new Node(element,null);
        //只有一个结点，header，tail都指向该结点
        tail = header;
        size++;
    }
    //返回链表的长度
    public int length(){
        return size;
    }
    //获取链表中索引为index处的元素
    public T get(int index){
        return getNodeByIndex(index).data;
    }
    //根据索引index获取指定位置的结点
    public Node getNodeByIndex(int index){
        if (index<0||index>size-1){
            throw new IndexOutOfBoundsException("线性表索引越界");
        }
        //从header结点开始
        Node current = header;
        for (int i = 0; i < size&&current!=null; i++,current=current.next) {
            if(i==index){
                return current;
            }
        }
        return null;
    }
    //查找链表中指定元素的索引
    public int locate(T element){
        //从头结点开始搜索
        Node current = header;
        for (int i = 0; i < size&&current!=null; i++,current=current.next) {
            if(current.data.equals(element)){
                return i;
            }
        }
        return -1;
    }
    //向链表中指定位置插入一个元素
    public void insert(T element,int index){
        if(index<0||index>size){
            throw new IndexOutOfBoundsException("线性表索引越界");
        }
        //如果还是空链表
        if (header==null){
            add(element);
        }else{
            //当index为0时，即在链表头插入
            if (index==0){
                addAtHeader(element);
            }else{
                //获取插入点的前一个结点
                Node prev = getNodeByIndex(index-1);
                //挂链
                prev.next = new Node(element,prev.next);
                size++;
            }
        }
    }
    //采用尾插法为链表添加新结点
    public void add(T element){
        //如果该链表还是空链表
        if (header==null){
            header = new Node(element,null);
            //只有一个结点，header，tail都指向该结点
            tail = header;
        }else{
            //创建新结点
            Node newNode = new Node(element,null);
            //让尾结点的next指向新增的结点
            tail.next = newNode;
            //尾指针后移
            tail = newNode;
        }
        size++;
    }
    //采用头插法为链表添加新结点
    public void addAtHeader(T element){
        //创建新结点，让新结点的next指向原来的header
        //并以新结点作为新的header
        header = new Node(element,header);
        //如果插入之前是空链表
        if(tail==null){
            tail = header;
        }
        size++;
    }
    //删除链表中指定索引处的元素
    public T delete(int index){
        if(index<0||index>size-1){
            throw new IndexOutOfBoundsException("线性表索引越界");
        }
        Node del = null;
        //如果被删除的结点是header结点
        if (index==0){
            del=header;
            header=header.next;
        }else{
            //获取删除点的前一个结点
            Node prev = getNodeByIndex(index-1);
            //获取将要被删除的结点
            del = prev.next;
            //让被删除结点的next指向被删除结点的下一个结点
            prev.next = del.next;
            //将删除了的结点的next属性赋值为null
            del.next = null;
        }
        size--;
        return del.data;
    }
    //删除链表中最后一个元素
    public T remove(){
        return delete(size-1);
    }
    //判断链表是否为空表
    public boolean isEmpty(){
        return size == 0;
    }
    //清空线性表
    public void clear(){
        //将header、tail赋为null
        header = null;
        tail = null;
        size = 0;
    }
    //重写toString方法
    public String toString(){
        //链表为空表时
        if (isEmpty()){
            return "[]";
        }else{
            StringBuilder sb = new StringBuilder("[");
            for (Node current = header;current!=null;current = current.next){
                sb.append(current.data+",");
            }
            int len = sb.length();
            return sb.delete(len-1,len).append("]").toString();
        }
    }
}
