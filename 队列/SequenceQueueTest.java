package com.Fengkuangjava.队列;

public class SequenceQueueTest {
    public static void main(String[] args) {
        SequenceQueue<String> queue = new SequenceQueue<>();
        //添加元素
        queue.add("aaaaa");
        queue.add("bbbbb");
        queue.add("ccccc");
        queue.add("ddddd");
        System.out.println(queue);
        System.out.println(queue.element());
        System.out.println(queue.remove());
        System.out.println(queue);
    }
}
