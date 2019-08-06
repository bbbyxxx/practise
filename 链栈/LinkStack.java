package com.Fengkuangjava.链栈;

import com.Fengkuangjava.单链表.LinkList;

public class LinkStack<T> {
    //定义一个内部类Node，Node实例代表链栈的结点
    private class Node{
        //保存结点数据
        private T data;
        private Node next;
        public Node(){

        }
        public Node(T data,Node next){
            this.data = data;
            this.next = next;
        }
    }
    //保存该链栈的栈顶元素
    private Node top;
    //保存该链栈中已包含的结点数
    private int size;
    //创建空链栈
    public LinkStack(){
        top = null;
    }
    //以指定数据元素来创建链栈，该链栈只有一个元素
    public LinkStack(T element){
        top = new Node(element,null);
        size++;
    }
    //返回链栈的长度
    public int length(){
        return size;
    }
    //进栈
    public void push(T element){
        //让top指向新创建的元素，新元素的next引用指向原来的栈顶元素
        top = new Node(element,top);
        size++;
    }
    //出栈
    public T pop(){
        Node oldTop = top;
        //让top指向原栈顶元素下一个
        top = top.next;
        //释放原来栈顶元素的引用
        oldTop.next = null;
        size--;
        return oldTop.data;
    }
    //访问栈顶元素，但不删除栈顶元素
    public T peek(){
        return top.data;
    }
    //判断链栈是否为空
    public boolean isEmpty(){
        return size == 0;
    }
    //清空链栈
    public void clear(){
        top = null;
        size = 0;
    }
    //重写toString方法
    public String toString(){
        if (isEmpty()){
            return ("[]");
        }else{
            StringBuilder sb = new StringBuilder("[");
            for (Node current = top;current!=null;current = current.next ){
                sb.append(current.data+",");
            }
            int len = sb.length();
            return sb.delete(len-1,len).append("]").toString();
        }
    }
}
