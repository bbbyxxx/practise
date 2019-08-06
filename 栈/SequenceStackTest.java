package com.Fengkuangjava.栈;

public class SequenceStackTest {
    public static void main(String[] args) {
        SequenceStack<String> stack = new SequenceStack<>();
        //入栈
        stack.push("aaaaa");
        stack.push("bbbbb");
        stack.push("ccccc");
        stack.push("ddddd");
        System.out.println(stack);
        //访问栈顶元素
        System.out.println(stack.peek());
        //弹出一个元素
        System.out.println(stack.pop());
        System.out.println(stack);
    }
}
